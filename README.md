# Android System Service IPC Example

In Android system, the main IPC is the **binder**.
App can invoke a API from other app by **binder**, or it can create a **binder** service.

And you can make many system services for customing a ROM.
Here we create many base codes for creating a system service in native code c level and Java code level.

## How to install

**Important**:
* Base environment: Ubuntu 12.04

### Under AOSP

Compile them by AOSP `mm`.

**AOSP should have compiled.**

```
# In AOSP topdir
## source
source build/envsetup.sh
## lunch
lunch XXXX

# to source code
cd android_system_service_example
# Compile
mm
```

### With Android SDK & NDK

System service Binder API is a hack techincal for customing ROM, so the system binder API invoking is also the hack techincal.
Such as reflecting in Java and linking binder header in native codes.

* Java code, you can use SDK to compile.

#### NDK for native code

```
#Go to sourcecode
cd android_system_service_example/NDKBuild
#Invoke NDK Command
XXXXXX/bins/android-ndk-r10c/ndk-build
```

For natice c code, there is not a better way for compiling in NDK because of some Binder APIs which are not Supported in NDK.
If we want to make compiling in NDK, we need to copy a lot of frameworks header files.
So here I copy headers and shared libraries for compiling as demo.

And the environment is:

        PLATFORM_VERSION_CODENAME=REL
        PLATFORM_VERSION=4.4
        TARGET_PRODUCT=aosp_mako
        TARGET_BUILD_VARIANT=userdebug
        TARGET_BUILD_TYPE=release
        TARGET_BUILD_APPS=
        TARGET_ARCH=arm
        TARGET_ARCH_VARIANT=armv7-a-neon
        TARGET_CPU_VARIANT=krait
        HOST_ARCH=x86
        HOST_OS=linux
        HOST_OS_EXTRA=Linux-3.2.0-60-generic-x86_64-with-Ubuntu-12.04-precise
        HOST_BUILD_TYPE=release
        BUILD_ID=KRT16S
        OUT_DIR=out

## Running

Because of using system API, the program should have **SYSTEM** permission.

* Native code: running in **root**
* Java code: sign by **platfrom certificate**


