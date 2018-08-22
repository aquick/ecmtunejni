LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := gmp-prebuilt
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libgmp.so
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include/$(TARGET_ARCH_ABI)
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := ecmtunejni
LOCAL_SRC_FILES := org_gmplib_gmpjni_ECMTune.cpp bench_mulredc.c mpmod.c tune.c mul_lo.c listz.c auxlib.c ks-multiply.c schoen_strass.c polyeval.c median.c ecm_ntt.c ntt_gfp.c mpzspv.c mpzspm.c sp.c spv.c spm.c auxarith.c
LOCAL_CFLAGS := -O2 -DTUNE
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include/$(TARGET_ARCH_ABI)
LOCAL_SHARED_LIBRARIES := gmp-prebuilt
include $(BUILD_SHARED_LIBRARY)
