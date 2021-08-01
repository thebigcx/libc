#pragma once

#include <sys/types.h>
#include <sys/stat.h>

ssize_t read(int fd, void* buf, size_t count);
ssize_t write(int fd, const void* buf, size_t count);
int close(int fd);
off_t lseek(int fd, off_t offset, int whence);
int execve(const char* pathname, char* const argv[], char* const envp[]);
pid_t getpid();
pid_t fork();
int chdir(const char* path);
char* getcwd(char* buf, size_t size);
int stat(const char* restrict pathname, struct stat* restrict statbuf);
unsigned int sleep(unsigned int seconds);
