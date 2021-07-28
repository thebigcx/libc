#include <unistd.h>
#include <libc/sysdeps-internal.h>

int open(const char* filename, int flags, mode_t mode)
{
	int fd;
	int err = sys_open(filename, flags, mode, &fd);

	if (err)
	{
		// TODO: set errno
		return err;
	}

	return fd;
}

int close(int fd)
{
	int err = sys_close(fd);
	
	if (err)
	{
		// TODO set errno
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





