#ifndef __KSU_H_KLOG
#define __KSU_H_KLOG

#include <linux/printk.h>

#ifdef pr_fmt
#undef pr_fmt
#define pr_fmt(fmt) "KernelSU: " fmt
#endif

#ifndef TWA_RESUME
#define TWA_RESUME true
#endif

#include <linux/version.h>
#include <linux/uaccess.h>

#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 8, 0)
#ifndef strncpy_from_user_nofault
#define strncpy_from_user_nofault strncpy_from_unsafe_user
#endif
#ifndef copy_from_user_nofault
#define copy_from_user_nofault probe_user_read
#endif
#endif

#endif
