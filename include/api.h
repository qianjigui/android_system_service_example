#ifndef __DEMO_BINDER_API__
#define __DEMO_BINDER_API__ 1

#include <binder/Parcel.h>
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Log.h>
#include <utils/String16.h>
using namespace android;

#define SERVICE_NAME "android.binder.example"
#define META_INTERFACE_NAME "android.binder.example.IDemoAPI"


namespace demo_api {

    enum DEMO_API_ENUM{
        GET_NAME=IBinder::FIRST_CALL_TRANSACTION, GET_FULL_NAME, SUM
    };

    class IDemoAPI : public IInterface
    {
        public:
            DECLARE_META_INTERFACE(DemoAPI);
            virtual char* getName() = 0;
            virtual String16* getFullName(String16* l) = 0;
            virtual int sum(int a, int b) = 0;
    };

    class BpDemoAPI : public BpInterface<IDemoAPI>
    {
        public:
            BpDemoAPI(const sp<IBinder>& impl );
            virtual char* getName();
            virtual String16* getFullName(String16* l);
            virtual int sum(int a, int b);
    };

}//end of namespace demo_api

#endif
