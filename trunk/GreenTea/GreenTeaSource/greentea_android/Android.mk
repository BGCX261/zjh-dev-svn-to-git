LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := greentea_static

LOCAL_MODULE_FILENAME := libgreentea

# Go through all directories and sub directories
define walk
    $(wildcard $(1)) $(foreach e, $(wildcard $(1)/*), $(call walk, $(e)))
endef

# Classes
ALLFILES = $(call walk, $(LOCAL_PATH)/..)

# Filter out all *.cpp files
FILE_LIST = $(filter %.cpp, $(ALLFILES))

# All cpp files
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..

LOCAL_C_INCLUDES := $(LOCAL_PATH)/..
                                 
include $(BUILD_STATIC_LIBRARY)
