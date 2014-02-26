#include "server.h"
#include <binder/IPCThreadState.h>

namespace demo_api{
    char* DemoAPI::getName(){
        return ("DemoAPI");
    };

    String16* DemoAPI::getFullName(String16* part){
        String16* s = new String16("DemoAPI ");
        s->append(*part);
        return s;
    };

    int DemoAPI::sum(int a, int b){
        ALOGE("Binder Service: %d + %d",a,b);
        return a+b;
    };

    /*
     * onTransact unpack data
     */
    status_t BnDemoAPI::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
    {
        //Here, to check the calling permissions
        IPCThreadState* self = IPCThreadState::self();
        ALOGE("Calling MSG: PID=%d, UID=%d",self->getCallingPid(),self->getCallingUid());

        //For Client Read exception code
        reply->writeInt32(0);

        switch(code)
        {
            case GET_NAME:
                {
                    CHECK_INTERFACE(IDemoAPI, data, reply);
                    reply->writeCString(getName());
                    return NO_ERROR;
                }break;
            case GET_FULL_NAME:
                {
                    CHECK_INTERFACE(IDemoAPI, data, reply);
                    String16* s = new String16(data.readString16());
                    reply->writeString16(*getFullName(s));
                    return NO_ERROR;
                }break;
            case SUM:
                {
                    CHECK_INTERFACE(IDemoAPI, data, reply);
                    int a,b;
                    data.readInt32(&a);
                    data.readInt32(&b);
                    reply->writeInt32(sum(a,b));
                    return NO_ERROR;
                }break;
            default:break;
        }
        return NO_ERROR;
    }
}//end of namespace demo_api
