OUTPUT_FORMAT(pei-x86-64)
ENTRY(efi_main)

SECTIONS
{
  .text 0x200000 : {
    *(.text)
    *(.data)
    *(.rodata)
  }
  .bss : {
    *(.bss)
  }
}

