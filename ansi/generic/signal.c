#include <signal.h>
#include <unistd.h>
#include <os/syscall.h>

int kill(pid_t pid, int sig)
{
	return syscall(SYS_KILL, pid, sig);
}

int raise(int sig)
{
    return kill((int)getpid(), sig);
}
