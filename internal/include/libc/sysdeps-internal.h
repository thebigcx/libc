#pragma once

#include <sys/types.h>
#include <signal.h>
#include <dirent.h>
#include <time.h>

// API: Return value error code, last parameter actual return value

int sys_open(const char* pathname, int flags, mode_t mode, int* fd);
int sys_close(int fd);
int sys_read(int fd, void* buf, size_t cnt, ssize_t* bytes_read);
int sys_write(int fd, const void* buf, size_t cnt, ssize_t* bytes_written);
int sys_exit(int status);
int sys_kill(pid_t pid, int sig);
int sys_sigaction(int signum, const struct sigaction* act, struct sigaction* old);
pid_t sys_getpid();
int sys_fork(pid_t* pid);
int sys_execve(const char* pathname, char* const argv[], char* const envp[]);
int sys_chdir(const char* path);
int sys_getcwd(char* buf, size_t size, char** ret);
int sys_readdir(int fd, struct dirent** dirents);
int sys_opendir(const char* name, int* dir);
int sys_closedir(int dir);
int sys_nanosleep(const struct timespec* req, struct timespec* rem);
int sys_lseek(int fd, off_t off, int whence, off_t* npos);
int sys_ioctl(int fd, unsigned long request, void* argp);
