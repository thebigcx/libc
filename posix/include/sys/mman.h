#pragma once

#include <stddef.h>

#define PROT_NONE 	0x00
#define PROT_READ 	0x01
#define PROT_WRITE 	0x02
#define PROT_EXEC  	0x04

#define MAP_SHARED  0x01
#define MAP_PRIVATE	0x02

void* mmap(void* addr, size_t length, int prot, int flags, int fd, off_t offset);
int munmap(void* addr, size_t length);
