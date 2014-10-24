LOCAL_PATH := $(call my-dir)

BINDERDEMO_C_INCLUDES := frameworks/base/include/ \
    system/core/include/

include $(call all-makefiles-under,$(LOCAL_PATH))
