#include <sys/mman.h>
#include <errno.h>
#include <libc/sysdeps-internal.h>

void* mmap(void* addr, size_t length, int prot, int flags, int fd, off_t offset)
{
    void* ret;
    int e = sys_mmap(addr, length, prot, flags, fd, offset, &ret); 

    if (e)
    {
        errno = e;
        return (void*)-1;
    }

    return ret;
}

int munmap(void* addr, size_t length)
{
    int e = sys_munmap(addr, length);

    if (e)
    {
        errno = e;
        return -1;
    }

    return 0;
}
