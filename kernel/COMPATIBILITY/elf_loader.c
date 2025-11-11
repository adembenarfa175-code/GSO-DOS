#include "../GSO_KERNEL.H"

int elf_load(const char* path) {
    // منطق تحميل ELF (رأس، أقسام، ربط ديناميكي).
    gso_print("DEBUG: Loading 64-bit ELF binary/library: ");
    gso_print(path);
    gso_print("\n");
    return 0;
}
