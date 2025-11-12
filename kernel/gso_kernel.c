<<<<<<< HEAD
#include "GSO_KERNEL.H"
#include "COMPATIBILITY/gso_exec.h" // لاستخدام Execution Manager
=======
#include "gso_kernel.h"
#include "compatibility/gso_exec.h"
>>>>>>> development

// Placeholder for gso_print implementation
void gso_print(const char* message) {
    // Will be implemented using the terminal driver (GOP)
}

<<<<<<< HEAD
// دالة تهيئة الKernel التي يتم استدعاؤها من GSOBOOT.EFI
=======
// Kernel entry point called from GSOBOOT.EFI
>>>>>>> development
void kernel_main(gso_ptr_t memory_map_ptr, gso_ptr_t screen_info_ptr) {

    gso_terminal_init(screen_info_ptr);
    gso_print("GSO-OS Kernel V2.0: Starting 64-bit Long Mode...\n");

    gso_memory_init(memory_map_ptr);
    
<<<<<<< HEAD
    // 3. تهيئة Compatibility Layer لـ GSO-EXEC
=======
    // Initialize GSO-EXEC compatibility layer
>>>>>>> development
    gso_exec_init();
    gso_print("GSO-EXEC Compatibility Layer initialized.\n");

    // Start the Shell (the first program to execute)
    gso_process_manager_start("A:\\GSO_SHELL.GXE");

<<<<<<< HEAD
    // حلقة لا نهائية (الKernel تعمل دائماً)
=======
    // Kernel loop
>>>>>>> development
    while(1) {}
}

// Placeholder function implementations
void gso_terminal_init(gso_ptr_t screen_info_ptr) {}
void gso_memory_init(gso_ptr_t memory_map_ptr) {}
void gso_process_manager_start(const char* shell_path) {
    // Calls gso_exec_load()
}
