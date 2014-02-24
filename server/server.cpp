#include "server.h"

namespace demo_api{
    char* DemoAPI::getName(){
        return ("DemoAPI");
    };

    int DemoAPI::sum(int a, int b){
        ALOGE("Binder Service: %d + %d",a,b);
        return a+b;
    };

    status_t BnDemoAPI::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
    {
        reply->writeInt32(0);
        switch(code)
        {
            case GET_NAME:
                {
                    CHECK_INTERFACE(IDemoAPI, data, reply);
                    reply->writeCString(getName());
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
