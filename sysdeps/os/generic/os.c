#include <libc/sysdeps-internal.h>
#include <os/syscall.h>

int sys_open(const char* pathname, int flags, mode_t mode, int* fd)
{
	long ret = syscall(SYS_open, pathname, flags, mode);
	
	*fd = ret;

	if (ret < 0)
		return ret;

	return 0;
}

int sys_close(int fd)
{
	return syscall(SYS_close, fd);
}

int sys_read(int fd, void* buf, size_t cnt, ssize_t* bytes_read)
{
	ssize_t ret = syscall(SYS_read, fd, buf, cnt);

	if (ret < 0)
		return ret;

	*bytes_read = ret;
	return 0;
}

int sys_write(int fd, const void* buf, size_t cnt, ssize_t* bytes_written)
{
	ssize_t ret = syscall(SYS_write, fd, buf, cnt);

	if (ret < 0)
        return ret;

	*bytes_written = ret;
	return 0;
}

int sys_exit(int status)
{
	syscall(SYS_exit, status);
	return 0;
}

pid_t sys_getpid()
{
	return (pid_t)syscall(SYS_getpid);
}

int sys_kill(pid_t pid, int sig)
{
	return syscall(SYS_kill, pid, sig);
}

/*int sys_sigaction(int signum, const struct sigaction* act, struct sigaction* old)
{
	return syscall(SYS_SIGACTION, signum, act, old);
}*/

int sys_fork(pid_t* pid)
{
	pid_t ret = syscall(SYS_fork);
	if (ret < 0)
	{
		return -1;
	}

	*pid = ret;
	return 0;
}

int sys_execve(const char* pathname, char* const argv[], char* const envp[])
{
	int e = syscall(SYS_execve, pathname, argv, envp);
	return e;
}

/*int sys_chdir(const char* path)
{
	return syscall(SYS_CHDIR, path);
}*/

/*int sys_getcwd(char* buf, size_t size, char** ret)
{
	char* cwd = (char*)syscall(SYS_GETCWD, buf, size);

	if (!cwd)
		return -1;
	
	*ret = cwd;
	return 0;
}*/

int sys_readdir(int fd, struct dirent** dirents)
{
	return -1;
}

int sys_opendir(const char* name, int* dir)
{
	return sys_open(name, 0, 0, dir);
}

int sys_closedir(int dir)
{
	return sys_close(dir);
}

/*int sys_nanosleep(const struct timespec* req, struct timespec* rem)
{
	return syscall(SYS_NANOSLEEP, req, rem);	
}*/

int sys_lseek(int fd, off_t off, int whence, off_t* noff)
{
    off_t ret = syscall(SYS_lseek, fd, off, whence);
    
    *noff = ret;
    
    if (ret < 0)
        return ret;

    return 0;
}

int sys_ioctl(int fd, unsigned long request, void* argp)
{
    return syscall(SYS_ioctl, fd, request, argp);
}

int sys_mmap(void* addr, size_t length, int prot, int flags, int fd, off_t offset, void** ret)
{
    void* mapped_addr = (void*)syscall(SYS_mmap, addr, length, prot, flags, fd, offset);

    *ret = mapped_addr;

    return 0;
}

int sys_munmap(void* addr, size_t length)
{
    return syscall(SYS_munmap, addr, length);
}
