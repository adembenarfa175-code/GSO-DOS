# GSO-OS Kernel Makefile

CC = x86_64-w64-mingw32-gcc
CFLAGS = -Wall -Wextra -std=c99 -ffreestanding -m64

KERNEL_OBJS = gso_kernel.o compatibility/gso_exec.o \
              compatibility/dos_loader.o compatibility/elf_loader.o \
              compatibility/gxe_loader.o

all: ../gsoos.bin

../gsoos.bin: $(KERNEL_OBJS)
$(CC) $(CFLAGS) -T kernel.lds -o ../gsoos.bin $(KERNEL_OBJS) 

.c.o:
$(CC) $(CFLAGS) -c $< -o $@

clean:
rm -f *.o compatibility/*.o ../gsoos.bin
