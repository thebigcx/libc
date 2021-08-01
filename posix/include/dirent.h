#pragma once

#include <sys/types.h>

struct dirent
{
	ino_t 			d_ino;
	off_t 			d_off;
	unsigned short	d_reclen;
	unsigned char	d_type;
	char			d_name[256];
};

struct __libc_dir
{
	int handle;
};

typedef struct __libc_dir DIR;

struct dirent* readdir(DIR* dirp);
DIR* opendir(const char* name);
int closedir(DIR* dirp);
