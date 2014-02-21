#include "MyBinder.h"

namespace android {

MyBinder::MyBinder()
    :   BnMyBinder(), Thread(false)
{

}

MyBinder::~MyBinder()
{

}

status_t MyBinder::onTransact(
    uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
    switch (code) {

    default:
        return BBinder::onTransact(code, data, reply, flags);
    }
    return NO_ERROR;
}


bool MyBinder::threadLoop()
{
    return true;
}

}; // namespace android
