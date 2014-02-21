LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= server.cpp main.cpp

LOCAL_SHARED_LIBRARIES := libutils libbinder liblog

LOCAL_C_INCLUDES := $(LOCAL_PATH) $(LOCAL_PATH)/../include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../include \
    frameworks/base/include/ \
    system/core/include/

LOCAL_STATIC_LIBRARIES := binderTC_Stub

LOCAL_MODULE:= binderTSer

include $(BUILD_EXECUTABLE)
