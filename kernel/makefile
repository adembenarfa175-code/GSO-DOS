# KERNEL/MAKEFILE لـ GSO-DOS

CC = x86_64-w64-mingw32-gcc
CFLAGS = -Wall -Wextra -std=c99 -ffreestanding -m64

KERNEL_OBJS = GSO_KERNEL.o COMPATIBILITY/gso_exec.o \
              COMPATIBILITY/dos_loader.o COMPATIBILITY/elf_loader.o \
              COMPATIBILITY/gxe_loader.o

all: ../GSODOS.BIN

../GSODOS.BIN: $(KERNEL_OBJS)
$(CC) $(CFLAGS) -T kernel.lds -o ../GSODOS.BIN $(KERNEL_OBJS) 

.c.o:
$(CC) $(CFLAGS) -c $< -o $@

clean:
rm -f *.o COMPATIBILITY/*.o ../GSODOS.BIN

