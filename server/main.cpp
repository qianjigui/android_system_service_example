#include "server.h"

int main(int argc, char *argv[])
{
    sp<ProcessState> proc(ProcessState::self());
    //get service manager
    sp<IServiceManager> sm = defaultServiceManager();

    sm->addService(String16(SERVICE_NAME),new demo_api::DemoAPI());
    ALOGE("%s service is starting.....",SERVICE_NAME);
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();

    return 0;
}

