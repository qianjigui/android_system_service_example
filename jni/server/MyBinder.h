#include <binder/BinderService.h>

#include "IMyBinder.h"

namespace android {

class MyBinder :
        public BinderService<MyBinder>,
        public BnMyBinder,
        protected Thread
{
public:
    static char const* getServiceName() { return "demo.MyBinder"; }

    MyBinder();
    virtual ~MyBinder();


    virtual status_t onTransact(
        uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags);

    virtual bool        threadLoop();
};

}; // namespace android
