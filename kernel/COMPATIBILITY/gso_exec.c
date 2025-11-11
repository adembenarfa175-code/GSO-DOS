#include "gso_exec.h"
#include "../GSO_KERNEL.H" // للوصول إلى دالة gso_print

// إعلانات اللودر
int dos_load(const char* path);
int elf_load(const char* path);
int gxe_load(const char* path);

void gso_exec_init() {
    // تهيئة جدول محاكاة الوضع الحقيقي أو أي هياكل بيانات مطلوبة
    gso_print("GSO-EXEC Loaders (DOS, ELF, GXE) registered.\n");
}

int gso_exec_load(const char* path) {
    // وظيفة وهمية لاكتشاف التنسيق
    if (strstr(path, ".GXE")) {
        return gxe_load(path);
    } else if (strstr(path, ".ELF")) {
        return elf_load(path);
    } else if (strstr(path, ".COM") || strstr(path, ".EXE") || strstr(path, ".SYS")) {
        return dos_load(path);
    }
    gso_print("Error: Unknown executable format.\n");
    return -1;
}
