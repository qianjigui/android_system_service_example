LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:=  IMyBinder.cpp

LOCAL_SHARED_LIBRARIES := libutils libbinder

LOCAL_C_INCLUDES:= $(LOCAL_PATH)/../include \
    frameworks/base/include/

LOCAL_MODULE_TAGS := debug

LOCAL_MODULE:= libmybinder

include $(BUILD_SHARED_LIBRARY)
