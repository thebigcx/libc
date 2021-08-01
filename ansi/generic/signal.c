#include <signal.h>
#include <unistd.h>
#include <libc/sysdeps-internal.h>

int kill(pid_t pid, int sig)
{
	return sys_kill(pid, sig);
}

int raise(int sig)
{
    return kill((int)getpid(), sig);
}

int sigaction(int signum, const struct sigaction* act, struct sigaction* old)
{
	return sys_sigaction(signum, act, old);
}
