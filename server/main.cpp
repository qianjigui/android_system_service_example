#include "server.h"

int main(int argc, char *argv[])
{
    sp<ProcessState> proc(ProcessState::self());
    //get service manager
    sp<IServiceManager> sm = defaultServiceManager();

    //Register a service with the SERVICE_NAME
    sm->addService(String16(SERVICE_NAME),new demo_api::DemoAPI());
    ALOGE("%s service is starting.....",SERVICE_NAME);
    //Start Service
    ProcessState::self()->startThreadPool();
    //Loop for waiting for request
    IPCThreadState::self()->joinThreadPool();

    return 0;
}

