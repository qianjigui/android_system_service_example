#include <stdint.h>
#include <sys/types.h>

#include <utils/RefBase.h>
#include <utils/Errors.h>

#include <binder/IInterface.h>


namespace android {
// ----------------------------------------------------------------------------

class IMyBinder : public IInterface
{
public:
    DECLARE_META_INTERFACE(MyBinder);
};

// ----------------------------------------------------------------------------

class BnMyBinder : public BnInterface<IMyBinder>
{
public:
    virtual status_t    onTransact( uint32_t code,
                                    const Parcel& data,
                                    Parcel* reply,
                                    uint32_t flags = 0);
};

// ----------------------------------------------------------------------------

}; // namespace android
