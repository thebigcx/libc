#include <unistd.h>
#include <libc/sysdeps-internal.h>

pid_t getpid()
{
	return sys_getpid();
}
