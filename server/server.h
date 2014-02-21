#ifndef __DEMO_BINDER_API_SERVER__
#define __DEMO_BINDER_API_SERVER__ 1

#include "api.h"

namespace demo_api{
    class BnDemoAPI: public BnInterface<IDemoAPI>
    {
        public:
            virtual status_t onTransact( uint32_t code,
                    const Parcel& data,
                    Parcel* reply,
                    uint32_t flags = 0);
    };
    class DemoAPI : public BnDemoAPI
    {
        public:
            virtual char* getName();
            virtual int sum(int a, int b);
    };
}

#endif
