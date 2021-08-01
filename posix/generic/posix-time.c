#include <unistd.h>
#include <time.h>
#include <libc/sysdeps-internal.h>

unsigned int sleep(unsigned int seconds)
{
	struct timespec ts =
	{
		.tv_sec  = seconds,
		.tv_nsec = 0
	};

	int e = sys_nanosleep(&ts, &ts);
	if (e < 0)
	{
		return ts.tv_sec;
	}

	return 0;
}
