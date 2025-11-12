OUTPUT_FORMAT("efi-app-x86_64")
OUTPUT_ARCH(i386:x86-64)
ENTRY(efi_main)

SECTIONS
{
    .text :
    {
        *(.text)
        *(.rodata)
    } = 0
    .data :
    {
        *(.data)
    }
    .bss :
    {
        *(.bss)
    }
}
