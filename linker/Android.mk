LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
    debugger.cpp \
    dlfcn.cpp \
    linker.cpp \
    linker_allocator.cpp \
    linker_environ.cpp \
    linker_libc_support.c \
    linker_phdr.cpp \
    rt.cpp \

LOCAL_SRC_FILES_arm     := arch/arm/begin.S
LOCAL_SRC_FILES_arm64   := arch/arm64/begin.S
LOCAL_SRC_FILES_x86     := arch/x86/begin.c
LOCAL_SRC_FILES_x86_64  := arch/x86_64/begin.S
LOCAL_SRC_FILES_mips    := arch/mips/begin.S
LOCAL_SRC_FILES_mips64  := arch/mips64/begin.S

# GNU assembler aborted with clang's output for linker.cpp:
# Assertion failure in get_line_subseg at
#   /s/ndk-toolchain/src/build/../binutils/binutils-2.24/gas/dwarf2dbg.c line 271.
ifeq ($(TARGET_ARCH),mips)
    LOCAL_CLANG_CFLAGS += -integrated-as
endif

LOCAL_LDFLAGS := \
    -shared \
    -Wl,-Bsymbolic \
    -Wl,--exclude-libs,ALL \

LOCAL_CFLAGS += \
    -fno-stack-protector \
    -Wstrict-overflow=5 \
    -fvisibility=hidden \
    -Wall -Wextra -Wunused -Werror \

LOCAL_CONLYFLAGS += \
    -std=gnu99 \

LOCAL_CPPFLAGS += \
    -std=gnu++11 \

# We need to access Bionic private headers in the linker.
LOCAL_CFLAGS += -I$(LOCAL_PATH)/../libc/

# we don't want crtbegin.o (because we have begin.o), so unset it
# just for this module
LOCAL_NO_CRT := true
# TODO: split out the asflags.
LOCAL_ASFLAGS := $(LOCAL_CFLAGS)

LOCAL_ADDITIONAL_DEPENDENCIES := $(LOCAL_PATH)/Android.mk

LOCAL_STATIC_LIBRARIES := libc_nomalloc

LOCAL_FORCE_STATIC_EXECUTABLE := true

LOCAL_MODULE := linker
LOCAL_MODULE_STEM_32 := linker
LOCAL_MODULE_STEM_64 := linker64
LOCAL_MULTILIB := both

# Leave the symbols in the shared library so that stack unwinders can produce
# meaningful name resolution.
LOCAL_STRIP_MODULE := keep_symbols

# Insert an extra objcopy step to add prefix to symbols.
# Note we are using "=" instead of ":=" to defer the evaluation,
# because LOCAL_2ND_ARCH_VAR_PREFIX or linked_module isn't set properly yet at this point.
LOCAL_POST_LINK_CMD = $(hide) $($(LOCAL_2ND_ARCH_VAR_PREFIX)TARGET_OBJCOPY) \
  --prefix-symbols=__dl_ $(linked_module)

include $(BUILD_EXECUTABLE)

include $(call first-makefiles-under,$(LOCAL_PATH))
