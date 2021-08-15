#pragma once

#include <stddef.h>
#include <sys/types.h>

#define PROT_NONE 	        0x0000
#define PROT_READ 	        0x0001
#define PROT_WRITE 	        0x0002
#define PROT_EXEC  	        0x0004

#define MAP_SHARED          0x0001
#define MAP_SHARED_VALIDATE 0x0002
#define MAP_PRIVATE	        0x0003

#define MAP_ANONYMOUS       0x0004
#define MAP_FIXED           0x0008

void* mmap(void* addr, size_t length, int prot, int flags, int fd, off_t offset);
int munmap(void* addr, size_t length);
