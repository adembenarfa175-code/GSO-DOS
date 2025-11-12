; uefi/uefi_gcon.asm - GSO-OS UEFI Graphics Console Module
; Handles screen output using UEFI services (64-bit)

BITS 64

; extern void gso_print_char(char c);

section .text
global uefi_gcon_init

uefi_gcon_init:
    ; Placeholder for initializing Graphics Output Protocol (GOP)
    ; Requires linking against the appropriate UEFI libraries.
    ret
