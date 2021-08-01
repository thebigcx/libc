#pragma once

#include <sys/types.h>
#include <abi-bits/abi.h>

#define O_RDONLY __LIBC_O_RDONLY
#define O_WRONLY __LIBC_O_WRONLY
#define O_RDWR   __LIBC_O_RDWR

int open(const char* pathname, int flags, mode_t mode);
