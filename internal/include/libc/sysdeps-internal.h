#pragma once

#include <sys/types.h>

// API: Return value error code, last parameter actual return value

int sys_open(const char* pathname, int flags, mode_t mode, int* fd);
int sys_close(int fd);
int sys_read(int fd, void* buf, size_t cnt, ssize_t* bytes_read);
int sys_write(int fd, const void* buf, size_t cnt, ssize_t* bytes_written);
int sys_exit(int status);
pid_t sys_getpid();
