#include <time.h>
#include <libc/sysdeps-internal.h>

int nanosleep(const struct timespec* req, struct timespec* rem)
{
	return sys_nanosleep(req, rem);
}
