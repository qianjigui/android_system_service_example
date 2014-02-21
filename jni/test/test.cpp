#include <utils/RefBase.h>
#include <utils/Log.h>
#include <binder/IServiceManager.h>

#include "IMyBinder.h"

using namespace android;
sp<IMyBinder> gMyBinder;

const sp<IMyBinder>& getMyBinderService()
{
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> binder;
    do {
        binder = sm->getService(String16("demo.MyBinder"));
        if (binder != 0)
            break;
        ALOGW("Service not published, waiting...");
        usleep(500000); // 0.5 s
     } while(true);

     /*if (mDeathNotifier == NULL) {
         mDeathNotifier = new DeathNotifier();
     }
     binder->linkToDeath(mDeathNotifier);*/

     gMyBinder = interface_cast<IMyBinder>(binder);

     ALOGE_IF(gMyBinder==0, "no Service!?");
     return gMyBinder;
}

int main()
{
    getMyBinderService();
    printf("get instance %p\n", gMyBinder.get());
    return 0;
}
