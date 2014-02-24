#ifndef __DEMO_BINDER_API_STUB__
#define __DEMO_BINDER_API_STUB__ 1

#include "api.h"

using namespace android;

namespace demo_api {

    BpDemoAPI::BpDemoAPI(const sp<IBinder>& impl ):BpInterface<IDemoAPI>(impl)
    {

    }
    char* BpDemoAPI::getName()
    {
        Parcel data, reply;
        data.writeInterfaceToken(IDemoAPI::getInterfaceDescriptor());
        remote()->transact(GET_NAME, data, &reply);
        return (char*)reply.readCString();
    }

    String16* BpDemoAPI::getFullName(String16* part)
    {
        Parcel data, reply;
        data.writeInterfaceToken(IDemoAPI::getInterfaceDescriptor());
        data.writeString16(*part);
        remote()->transact(GET_NAME, data, &reply);
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
        return (int)reply.readInt32();
    }

    IMPLEMENT_META_INTERFACE(DemoAPI,META_INTERFACE_NAME);

}//end of namespace demo_api

#endif
