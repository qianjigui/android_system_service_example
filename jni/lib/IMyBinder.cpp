#define LOG_TAG "MyBinder"

#include <stdint.h>
#include <sys/types.h>

#include <binder/Parcel.h>

#include "IMyBinder.h"

namespace android {

class BpMyBinder : public BpInterface<IMyBinder>
{
public:
    BpMyBinder(const sp<IBinder>& impl)
        : BpInterface<IMyBinder>(impl)
    {
    }
};

IMPLEMENT_META_INTERFACE(MyBinder, "demo.IMyBinder");

status_t BnMyBinder::onTransact(
    uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
     switch(code) {

        default:
            return BBinder::onTransact(code, data, reply, flags);
    }
}

}; // namespace android
