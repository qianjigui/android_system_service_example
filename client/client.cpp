#include "api.h"
using namespace android;
using namespace demo_api;

int main(int argc, char *argv[])
{
    sp<IBinder> binder;
    sp<ProcessState> proc(ProcessState::self());
    //get service manager
    sp<IServiceManager> sm = defaultServiceManager();

    do{
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

