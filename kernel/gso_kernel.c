#include "GSO_KERNEL.H"
#include "COMPATIBILITY/gso_exec.h" // لاستخدام مدير التنفيذ

void gso_print(const char* message) {
    // وظيفة وهمية (Placeholder) للطباعة عبر Terminal Driver
    // سيتم تنفيذها لاحقاً
}

// دالة تهيئة النواة التي يتم استدعاؤها من GSOBOOT.EFI
void kernel_main(gso_ptr_t memory_map_ptr, gso_ptr_t screen_info_ptr) {

    // 1. تهيئة الشاشة (باستخدام بيانات GOP التي مررها Bootloader)
    gso_terminal_init(screen_info_ptr);
    gso_print("GSO-DOS Kernel v0.1: Starting 64-bit Protected Mode...\n");

    // 2. تهيئة إدارة الذاكرة
    gso_memory_init(memory_map_ptr);
    
    // 3. تهيئة طبقة التوافق لـ GSO-EXEC
    gso_exec_init();
    gso_print("GSO-EXEC Compatibility Layer initialized.\n");

    // 4. بدء تشغيل الـ Shell/CMD (أول برنامج يتم تنفيذه)
    // نستخدم صيغة GXE لغلاف GSO-DOS الأصلي
    gso_process_manager_start("A:\\GSO_SHELL.GXE");

    // حلقة لا نهائية (النواة تعمل دائماً)
    while(1) {}
}

// وظائف وهمية (Placeholders)
void gso_terminal_init(gso_ptr_t screen_info_ptr) {}
void gso_memory_init(gso_ptr_t memory_map_ptr) {}
void gso_process_manager_start(const char* shell_path) {
    // هنا يتم استدعاء gso_exec_load(shell_path)
}

