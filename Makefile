SOURCES := internal/generic/init.c				\
		   internal/generic/crt0.c  			\
		   ansi/generic/malloc.c				\
		   ansi/generic/math.c					\
		   ansi/generic/file.c					\
		   ansi/generic/printf.c				\
		   ansi/generic/stdio.c					\
		   ansi/generic/stdlib.c  				\
		   ansi/generic/convert.c				\
		   ansi/generic/rand.c					\
		   ansi/generic/string.c				\
		   ansi/generic/signal.c				\
		   ansi/generic/errno.c					\
		   posix/generic/file-io.c				\
		   posix/generic/posix-proc.c 			\
		   posix/generic/posix-time.c			\
		   posix/generic/mman.c					\
		   sysdeps/os/generic/os.c  			\

ASM :=     sysdeps/os/generic/syscall.S

OBJS := $(patsubst %.c, %.o, $(SOURCES)) $(patsubst %.S, %.o, $(ASM))
AR := libc.a
SO := libc.so
CRT0 := crt0.o
CFLAGS := -ffreestanding -fno-stack-protector -O2 -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable -nostdinc -Iansi/include -Iinternal/include -Iposix/include -Isysdeps/os/include

all: $(AR) $(SO) $(CRT0)

$(CRT0):
	@cp internal/generic/crt0.o .

$(AR): $(OBJS)
	@echo "    AR      $@"
	@ar rcs $@ $^

$(SO): $(OBJS)
	@echo "    LD      $@"
	@ld -shared -nostdlib -Bsymbolic -o $@ $^

%.o: %.c
	@echo "    CC      $@"
	@gcc $(CFLAGS) -c $< -o $@

%.o: %.S
	@echo "    AS      $@"
	@gcc -c $< -o $@

install:
	cp $(AR) $(ROOT)/usr/lib/
	cp $(SO) $(ROOT)/usr/lib/
	cp $(CRT0) $(ROOT)/usr/lib/
	cp -r ansi/include/* $(ROOT)/usr/include/
	cp -r posix/include/* $(ROOT)/usr/include/

.PHONY:
clean:
	@echo "    RM      $(SO) $(AR)"
	@rm -f $(OBJS) $(SO) $(AR) $(CRT0)
