
LOCAL_PATH:= $(call my-dir)

BINDERDEMO_C_INCLUDES := include \
    frameworks/base/include/ \
    system/core/include/

BINDERDEMO_LDLIBS += -Lshared_libraries

BINDERDEMO_LDLIBS += -llog -lutils -lbinder

include $(call all-makefiles-under,$(LOCAL_PATH))

