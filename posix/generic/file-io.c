#include <unistd.h>
#include <dirent.h>
#include <stddef.h>
#include <libc/sysdeps-internal.h>

int open(const char* filename, int flags, mode_t mode)
{
	int fd;
	int err = sys_open(filename, flags, mode, &fd);

	if (err)
	{
		// TODO: set errno
		return -1;
	}

	return fd;
}

int close(int fd)
{
	int err = sys_close(fd);
	
	if (err)
	{
		// TODO set errno
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
		// TODO: set errno
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
		// TODO: set errno
		return -1;
	}

	return bytes_written;
}

int chdir(const char* path)
{
	int e = sys_chdir(path);
	if (e != 0)
	{
		// TODO: set errno
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
		// TODO: set errno
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
