#include <stdlib.h>
#include <signal.h>
#include <libc/sysdeps-internal.h>

int abs(int n)
{
    if (n < 0) return -n;
    return n;
}

void abort()
{
    raise(SIGABRT);
}

void exit(int status)
{
	sys_exit(status);
}
