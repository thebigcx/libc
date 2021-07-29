#include <libc/libc-internal.h>

void __libc_init()
{
    __malloc_init();
}
