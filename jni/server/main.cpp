#include <binder/BinderService.h>
#include "MyBinder.h"


using namespace android;

int main(int argc, char** argv) {
    MyBinder::publishAndJoinThreadPool();
    return 0;
}
