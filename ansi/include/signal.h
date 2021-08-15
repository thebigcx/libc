#pragma once

#include <sys/types.h>
#include <stdint.h>

#define SIGABRT     0
#define SIGALRM     1
#define SIGBUS      2
#define SIGCHLD     3
#define SIGCONT     4
#define SIGFPE      5
#define SIGHUP      6
#define SIGILL      7
#define SIGINFO     8
#define SIGINT      9
#define SIGKILL     10
#define SIGPIPE     11
#define SIGPOLL     12
#define SIGPROF     13
#define SIGQUIT     14
#define SIGSEGV     15
#define SIGSTOP     16
#define SIGTSTP     17
#define SIGSYS      18
#define SIGTERM     19
#define SIGTRAP     20
#define SIGTTIN     21
#define SIGTTOU     22
#define SIGURG      23
#define SIGUSR1     24
#define SIGUSR2     25
#define SIGVTALRM   26
#define SIGXCPU     27
#define SIGXFSZ     28

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
