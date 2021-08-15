#include <unistd.h>
#include <libc/sysdeps-internal.h>
#include <errno.h>

pid_t getpid()
{
	return sys_getpid();
}

pid_t fork()
{
	pid_t pid;
	int e = sys_fork(&pid);
	if (e != 0)
	{
		errno = e;
        return -1;
	}

	return pid;
}

int execve(const char* pathname, char* const argv[], char* const envp[])
{
	int e = sys_execve(pathname, argv, envp);
	errno = e;
    return -1;
}
