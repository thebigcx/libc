#pragma once

#include <stdint.h>

#define SYS_read        	0
#define SYS_write       	1
#define SYS_open        	2
#define SYS_close       	3
#define SYS_fork            4
#define SYS_exit            5
#define SYS_execve          6
#define SYS_mmap            7
#define SYS_munmap          8
#define SYS_stat            9
#define SYS_kill            10
#define SYS_getpid          11
#define SYS_lseek           12
#define SYS_ioctl           13

uint64_t syscall(uint64_t sysno, ...);
