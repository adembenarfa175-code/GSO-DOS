; uefi/uefi_init.asm - GSO-OS Low-Level Initialization
; Prepares environment for the C kernel main function

BITS 64

global transition_to_long_mode

transition_to_long_mode:
    ; Placeholder for final assembly steps before calling kernel_main
    ; This is usually done inside the C bootloader for UEFI applications
    ret
