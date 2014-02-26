#ifndef __DEMO_BINDER_API__
#define __DEMO_BINDER_API__ 1
/*
 * Should be compiled in opensource
 */
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

    /*
     * API serial code, 与Java不同, C/CPP的模块间没有统一的唯一识别码.
     * 因此CPP的异常机制基本是个摆设. 这里通过Binder内定的相同初始码(IBinder::FIRST_CALL_TRANSACTION)
     * 进行编码排列.
     */
    enum DEMO_API_ENUM{
        GET_NAME=IBinder::FIRST_CALL_TRANSACTION, GET_FULL_NAME, SUM
    };

    /**
     * Binder Shared interface, stub code
     */
    class IDemoAPI : public IInterface
    {
        public:
            DECLARE_META_INTERFACE(DemoAPI);

            /*
             * Service API
             */
            virtual char* getName() = 0;
            /*
             * Java String should be encoded in String16
             */
            virtual String16* getFullName(String16* l) = 0;
            virtual int sum(int a, int b) = 0;
    };

    /*
     * The proxy between the Client and Server
     */
    class BpDemoAPI : public BpInterface<IDemoAPI>
    {
        public:
            BpDemoAPI(const sp<IBinder>& impl );
            virtual char* getName();
            virtual String16* getFullName(String16* l);
            virtual int sum(int a, int b);
    };


}//end of namespace demo_api

#endif //end of ifndef __DEMO_BINDER_API__
