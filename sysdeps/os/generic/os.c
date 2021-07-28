#include <libc/sysdeps-internal.h>
#include <os/syscall.h>

int sys_open(const char* pathname, int flags, mode_t mode, int* fd)
{
	long ret = syscall(SYS_OPEN, pathname, flags, mode);
	
	*fd = ret;

	if (ret < 0)
		return ret;

	return 0;
}

int sys_close(int fd)
{
	return syscall(SYS_CLOSE, fd);
}

int sys_read(int fd, void* buf, size_t cnt, ssize_t* bytes_read)
{
	ssize_t ret = syscall(SYS_READ, fd, buf, cnt);

	if (ret < 0)
		return ret;

	*bytes_read = ret;
	return 0;
}

int sys_write(int fd, const void* buf, size_t cnt, ssize_t* bytes_written)
{
	ssize_t ret = syscall(SYS_WRITE, fd, buf, cnt);

	if (ret < 0)
			return ret;

	*bytes_written = ret;
	return 0;
}
