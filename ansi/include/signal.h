#pragma once

#include <sys/types.h>
#include <stdint.h>

#define SIGINT  0
#define SIGSEG  1
#define SIGABRT 2

struct sigaction
{
	void (*sa_handler)(int);
	void (*sa_sigaction)(int);
	uint64_t mask;
	int sa_flags;
	void (*sa_restorer)();
};

int kill(pid_t pid, int sig);
int raise(int sig);
int sigaction(int signum, const struct sigaction* act, struct sigaction* old);
