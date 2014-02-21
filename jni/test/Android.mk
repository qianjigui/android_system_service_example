LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:=  test.cpp

LOCAL_SHARED_LIBRARIES := \
    libmybinder libutils libbinder libcutils

LOCAL_C_INCLUDES:= $(LOCAL_PATH)/../include \
    frameworks/base/include/ \
    system/core/include/

LOCAL_MODULE_TAGS := debug

LOCAL_MODULE:= testb

include $(BUILD_EXECUTABLE)
