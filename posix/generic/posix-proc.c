#include <unistd.h>
#include <libc/sysdeps-internal.h>

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
		// TODO: set error code
		return -1;
	}

	return pid;
}

int execve(const char* pathname, char* const argv[], char* const envp[])
{
	int e = sys_execve(pathname, argv, envp);
	// TODO: set error code
	return -1;
}
