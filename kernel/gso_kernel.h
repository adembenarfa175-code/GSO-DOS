#ifndef GSO_KERNEL_H
#define GSO_KERNEL_H

#include <stdint.h>
#include <stddef.h>

// Data types passed from UEFI Bootloader
typedef uint64_t gso_ptr_t;

// Terminal and Memory Management
void gso_print(const char* message);
void gso_terminal_init(gso_ptr_t screen_info_ptr);
void gso_memory_init(gso_ptr_t memory_map_ptr);

// Process Management and Execution Manager (GSO-EXEC)
void gso_process_manager_start(const char* shell_path);

// Main Kernel Entry Point
void kernel_main(gso_ptr_t memory_map_ptr, gso_ptr_t screen_info_ptr);

#endif // GSO_KERNEL_H
