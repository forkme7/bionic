/*
 * Copyright (C) 2013 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

// This file perpetuates the mistakes of the past, but only for 32-bit targets.
#if !defined(__LP64__)

#include <pthread.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// These were accidentally declared in <unistd.h> because we stupidly used to inline
// getpagesize() and __getpageshift(). Needed for backwards compatibility with old NDK apps.
extern "C" {
  unsigned int __page_size = PAGE_SIZE;
  unsigned int __page_shift = 12;
}

// TODO: remove this backward compatibility hack (for jb-mr1 strace binaries).
extern "C" pid_t __wait4(pid_t pid, int* status, int options, struct rusage* rusage) {
  return wait4(pid, status, options, rusage);
}

// TODO: does anything still need this?
extern "C" int __open() {
  abort();
}

// TODO: does anything still need this?
extern "C" void** __get_tls() {
#include "private/__get_tls.h"
  return __get_tls();
}

// This non-standard function was in our <string.h> for some reason.
extern "C" void memswap(void* m1, void* m2, size_t n) {
  char* p = reinterpret_cast<char*>(m1);
  char* p_end = p + n;
  char* q = reinterpret_cast<char*>(m2);
  while (p < p_end) {
    char tmp = *p;
    *p = *q;
    *q = tmp;
    p++;
    q++;
  }
}

extern "C" int pthread_attr_setstackaddr(pthread_attr_t*, void*) {
  // This was removed from POSIX.1-2008, and is not implemented on bionic.
  // Needed for ABI compatibility with the NDK.
  return ENOSYS;
}

extern "C" int pthread_attr_getstackaddr(const pthread_attr_t* attr, void** stack_addr) {
  // This was removed from POSIX.1-2008.
  // Needed for ABI compatibility with the NDK.
  *stack_addr = (char*)attr->stack_base + attr->stack_size;
  return 0;
}

#endif
