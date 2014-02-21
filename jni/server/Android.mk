LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:=       \
    MyBinder.cpp \
    main.cpp

LOCAL_SHARED_LIBRARIES := \
    libmybinder libutils libbinder

LOCAL_C_INCLUDES:= $(LOCAL_PATH)/../include \
    frameworks/base/include/

LOCAL_MODULE_TAGS := debug

LOCAL_MODULE:= serverbinder

include $(BUILD_EXECUTABLE)
