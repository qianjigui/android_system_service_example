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
* For natice c code, there is not a better way for compiling in NDK because of some Binder APIs which are not Supported in NDK.
  If we want to make compiling in NDK, we need to copy a lot of frameworks header files.

## Running

Because of using system API, the program should have **SYSTEM** permission.

* Native code: running in **root**
* Java code: sign by **platfrom certificate**


