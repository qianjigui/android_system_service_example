#include "api.h"
using namespace android;
using namespace demo_api;

/*
 * ---------------------------------------------------------------------------
 *
 *  Client Proxy
 */
namespace demo_api {

    BpDemoAPI::BpDemoAPI(const sp<IBinder>& impl ):BpInterface<IDemoAPI>(impl)
    {

    }

    char* BpDemoAPI::getName()
    {
        Parcel data, reply;
        data.writeInterfaceToken(IDemoAPI::getInterfaceDescriptor());
        //By operation code to transact
        remote()->transact(GET_NAME, data, &reply);
        //Exception Code. In Java Level, aidl auto generate codes will process exceptioncode.
        reply.readExceptionCode();
        return (char*)reply.readCString();
    }

    String16* BpDemoAPI::getFullName(String16* part)
    {
        Parcel data, reply;
        data.writeInterfaceToken(IDemoAPI::getInterfaceDescriptor());
        data.writeString16(*part);
        remote()->transact(GET_FULL_NAME, data, &reply);
        reply.readExceptionCode();
        String16* s = new String16(reply.readString16());
        return s;
    }

    int BpDemoAPI::sum(int a, int b)
    {
        Parcel data, reply;
        data.writeInterfaceToken(IDemoAPI::getInterfaceDescriptor());
        data.writeInt32(a);
        data.writeInt32(b);
        remote()->transact(SUM, data, &reply);
        reply.readExceptionCode();
        return (int)reply.readInt32();
    }

}//end of namespace demo_api
/*
 * End of Client Proxy
 */

int main(int argc, char *argv[])
{
    sp<IBinder> binder;
    sp<ProcessState> proc(ProcessState::self());
    //get service manager
    sp<IServiceManager> sm = defaultServiceManager();

    do{
        //Search service by SERVICE_NAME
        binder = sm->getService(String16(SERVICE_NAME));
        if(binder != 0)
            break;
        sleep(1);
    }while(true);

    const sp<IDemoAPI>& bts = interface_cast<IDemoAPI>(binder);
    ALOGE("bindertest client is starting....."); 

    ALOGE("Service Name=%s",bts->getName());
    ALOGE("Service SUM %d+%d=%d",1,2,bts->sum(1,2));

    return 0;
}

