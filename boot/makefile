# GSO-OS Bootloader Makefile
# Targets: gsoboot.efi

CC      = x86_64-w64-mingw32-gcc
CFLAGS  = -Wall -Wextra -std=c99 -ffreestanding -mno-red-zone
LDFLAGS = -T gsoboot.lds -nostdlib

all: gsoboot.efi

gsoboot.efi: gsoboot.o
$(CC) $(CFLAGS) $(LDFLAGS) -o $@ gsoboot.o

gsoboot.o: gsoboot.c
$(CC) $(CFLAGS) -c $< -o $@

clean:
rm -f *.o gsoboot.efi
