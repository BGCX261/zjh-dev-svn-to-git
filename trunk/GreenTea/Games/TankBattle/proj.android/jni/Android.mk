LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

# Go through all files and folders
define walk
    $(wildcard $(1)) $(foreach e, $(wildcard $(1)/*), $(call walk, $(e)))
endef

#
ALLFILES = $(call walk, $(LOCAL_PATH)/../..)

# Go through all c/cpp files
FILE_LIST = $(filter %.cpp, $(ALLFILES))

LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../main
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../common
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../GreenTeaSource
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../FrameworkSource
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../FrameworkSource/Common
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../GameSource
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../GameSource/BehaviourScript
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../test


LOCAL_WHOLE_STATIC_LIBRARIES += greentea_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += chipmunk_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static



include $(BUILD_SHARED_LIBRARY)

$(call import-module,greentea_android)
$(call import-module,cocos2dx)
$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)
$(call import-module,CocosDenshion/android)
$(call import-module,extensions)
$(call import-module,external/Box2D)
$(call import-module,external/chipmunk)
