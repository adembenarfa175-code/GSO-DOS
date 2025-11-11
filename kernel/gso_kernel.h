#ifndef GSO_KERNEL_H
#define GSO_KERNEL_H

#include <stdint.h>
#include <stddef.h>

// تعريف أنواع البيانات التي سيتم تمريرها من UEFI Bootloader
typedef uint64_t gso_ptr_t;

// تهيئة التيرمينال الأساسي للطباعة
void gso_terminal_init(gso_ptr_t screen_info_ptr);
// تهيئة إدارة الذاكرة
void gso_memory_init(gso_ptr_t memory_map_ptr);
// تهيئة مدير العمليات و GSO-EXEC
void gso_process_manager_start(const char* shell_path);

// نقطة الدخول الرئيسية للنواة
void kernel_main(gso_ptr_t memory_map_ptr, gso_ptr_t screen_info_ptr);

#endif // GSO_KERNEL_H
