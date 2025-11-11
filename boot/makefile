# BOOT/MAKEFILE لـ GSO-DOS (بناء UEFI 64-bit)

# تعريف المُجمِّع المُتقاطع 64-بت
CC = x86_64-w64-mingw32-gcc

# تعريف اسم ملف UEFI الناتج
EFI_FILE = GSOBOOT.EFI

# ملف المصدر C
SOURCE = GSOBOOT.C

# الإعدادات القياسية لبناء UEFI (قد تتطلب تكييفًا مع حزمة SDK الفعلية)
CFLAGS = -Wall -Wextra -Werror -std=c99 -ffreestanding -fno-stack-protector -mno-red-zone -m64 -I/usr/include/efi
LDFLAGS = -nostdlib -Wl,-dll -Wl,--subsystem,10 -Wl,--entry,efi_main -T gsoboot.lds

# المكتبات (يجب أن تكون موجودة في بيئة البناء)
UEFI_LIBS = -l:libefi.a -l:libgnuefi.a

all: $(EFI_FILE)

$(EFI_FILE): $(SOURCE)
$(CC) $(CFLAGS) $(SOURCE) -o $(EFI_FILE) $(LDFLAGS) $(UEFI_LIBS)

clean:
rm -f $(EFI_FILE)
