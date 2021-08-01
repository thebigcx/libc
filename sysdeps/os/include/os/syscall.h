#pragma once

#include <stdint.h>

#define SYS_READ        	0
#define SYS_WRITE       	1
#define SYS_OPEN        	2
#define SYS_CLOSE       	3
#define SYS_MMAP        	4
#define SYS_IOCTL       	5
#define SYS_STAT        	6
#define SYS_FORK        	7
#define SYS_EXECVE      	8
#define SYS_WAITID      	9
#define SYS_EXIT        	10
#define SYS_NANOSLEEP   	11
#define SYS_LSEEK       	12
#define SYS_CREATETHREAD 	13
#define SYS_EXITTHREAD  	14
#define SYS_KILLTHREAD  	15
#define SYS_JOINTHREAD  	16
#define SYS_KILL     		17
#define SYS_GETPID      	18
#define SYS_SIGACTION		19
#define SYS_CHDIR			20
#define SYS_GETCWD			21

uint64_t syscall(uint64_t sysno, ...);
