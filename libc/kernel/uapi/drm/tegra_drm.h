/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _UAPI_TEGRA_DRM_H_
#define _UAPI_TEGRA_DRM_H_
#include <drm/drm.h>
struct drm_tegra_gem_create {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u64 size;
 __u32 flags;
 __u32 handle;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct drm_tegra_gem_mmap {
 __u32 handle;
 __u32 offset;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct drm_tegra_syncpt_read {
 __u32 id;
 __u32 value;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct drm_tegra_syncpt_incr {
 __u32 id;
 __u32 pad;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct drm_tegra_syncpt_wait {
 __u32 id;
 __u32 thresh;
 __u32 timeout;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 value;
};
#define DRM_TEGRA_NO_TIMEOUT (0xffffffff)
struct drm_tegra_open_channel {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 client;
 __u32 pad;
 __u64 context;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct drm_tegra_close_channel {
 __u64 context;
};
struct drm_tegra_get_syncpt {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u64 context;
 __u32 index;
 __u32 id;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct drm_tegra_syncpt {
 __u32 id;
 __u32 incrs;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct drm_tegra_cmdbuf {
 __u32 handle;
 __u32 offset;
 __u32 words;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 pad;
};
struct drm_tegra_reloc {
 struct {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 handle;
 __u32 offset;
 } cmdbuf;
 struct {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 handle;
 __u32 offset;
 } target;
 __u32 shift;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 pad;
};
struct drm_tegra_waitchk {
 __u32 handle;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 offset;
 __u32 syncpt;
 __u32 thresh;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct drm_tegra_submit {
 __u64 context;
 __u32 num_syncpts;
 __u32 num_cmdbufs;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 num_relocs;
 __u32 num_waitchks;
 __u32 waitchk_mask;
 __u32 timeout;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u32 pad;
 __u64 syncpts;
 __u64 cmdbufs;
 __u64 relocs;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 __u64 waitchks;
 __u32 fence;
 __u32 reserved[5];
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DRM_TEGRA_GEM_CREATE 0x00
#define DRM_TEGRA_GEM_MMAP 0x01
#define DRM_TEGRA_SYNCPT_READ 0x02
#define DRM_TEGRA_SYNCPT_INCR 0x03
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DRM_TEGRA_SYNCPT_WAIT 0x04
#define DRM_TEGRA_OPEN_CHANNEL 0x05
#define DRM_TEGRA_CLOSE_CHANNEL 0x06
#define DRM_TEGRA_GET_SYNCPT 0x07
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DRM_TEGRA_SUBMIT 0x08
#define DRM_IOCTL_TEGRA_GEM_CREATE DRM_IOWR(DRM_COMMAND_BASE + DRM_TEGRA_GEM_CREATE, struct drm_tegra_gem_create)
#define DRM_IOCTL_TEGRA_GEM_MMAP DRM_IOWR(DRM_COMMAND_BASE + DRM_TEGRA_GEM_MMAP, struct drm_tegra_gem_mmap)
#define DRM_IOCTL_TEGRA_SYNCPT_READ DRM_IOWR(DRM_COMMAND_BASE + DRM_TEGRA_SYNCPT_READ, struct drm_tegra_syncpt_read)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DRM_IOCTL_TEGRA_SYNCPT_INCR DRM_IOWR(DRM_COMMAND_BASE + DRM_TEGRA_SYNCPT_INCR, struct drm_tegra_syncpt_incr)
#define DRM_IOCTL_TEGRA_SYNCPT_WAIT DRM_IOWR(DRM_COMMAND_BASE + DRM_TEGRA_SYNCPT_WAIT, struct drm_tegra_syncpt_wait)
#define DRM_IOCTL_TEGRA_OPEN_CHANNEL DRM_IOWR(DRM_COMMAND_BASE + DRM_TEGRA_OPEN_CHANNEL, struct drm_tegra_open_channel)
#define DRM_IOCTL_TEGRA_CLOSE_CHANNEL DRM_IOWR(DRM_COMMAND_BASE + DRM_TEGRA_CLOSE_CHANNEL, struct drm_tegra_open_channel)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define DRM_IOCTL_TEGRA_GET_SYNCPT DRM_IOWR(DRM_COMMAND_BASE + DRM_TEGRA_GET_SYNCPT, struct drm_tegra_get_syncpt)
#define DRM_IOCTL_TEGRA_SUBMIT DRM_IOWR(DRM_COMMAND_BASE + DRM_TEGRA_SUBMIT, struct drm_tegra_submit)
#endif
