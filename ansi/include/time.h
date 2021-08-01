#pragma once

typedef long int time_t;

struct timespec
{
	time_t tv_sec; // seconds
	long   tv_nsec; // nanoseconds
};

int nanosleep(const struct timespec* req, struct timespec* rem);
