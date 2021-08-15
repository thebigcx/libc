#include <unistd.h>
#include <dirent.h>
#include <stddef.h>
#include <errno.h>
#include <libc/sysdeps-internal.h>

int open(const char* filename, int flags, mode_t mode)
{
	int fd;
	int err = sys_open(filename, flags, mode, &fd);

	if (err)
	{
        errno = err;
		return -1;
	}

	return fd;
}

int close(int fd)
{
	int err = sys_close(fd);
	
	if (err)
	{
        errno = err;
		return -1;
	}

	return 0;
}

ssize_t read(int fd, void* buf, size_t count)
{
	ssize_t bytes_read;
	int err = sys_read(fd, buf, count, &bytes_read);

	if (err)
	{
        errno = err;
		return -1;
	}

	return bytes_read;
}

ssize_t write(int fd, const void* buf, size_t count)
{
	ssize_t bytes_written;
	int err = sys_write(fd, buf, count, &bytes_written);

	if (err)
	{
        errno = err;
		return -1;
	}

	return bytes_written;
}

int chdir(const char* path)
{
	int e = sys_chdir(path);
	if (e != 0)
	{
        errno = e;
		return -1;
	}

	return 0;
}

char* getcwd(char* buf, size_t size)
{
	char* ret;
	int e = sys_getcwd(buf, size, &ret);

	if (e != 0)
	{
        errno = e;
		return NULL;
	}

	return ret;
}

struct dirent* readdir(DIR* dirp)
{
	return NULL;
}

DIR* opendir(const char* name)
{
	return NULL;
}

int closedir(DIR* dirp)
{
	return -1;
}

off_t lseek(int fd, off_t off, int whence)
{
    off_t npos;
    int err = sys_lseek(fd, off, whence, &npos);
    
    if (err)
    {
        errno = err;
        return -1;
    }

    return npos;
}

int ioctl(int fd, unsigned long request, void* argp)
{
    int ret = sys_ioctl(fd, request, argp);

    if (ret < 0)
    {
        errno = ret;
        return -1;
    }
    
    return ret; // Some ioctl's return non-negative outputs
}
