#include <efi.h>
#include <efilib.h>

/*
 * GSOBOOT.C - مُحمِّل الإقلاع الأساسي لنظام GSO-DOS (UEFI 64-bit)
 * الوظيفة: تهيئة بيئة UEFI، إعداد الذاكرة، والبحث عن نواة GSO-DOS.
 */

// اسم النواة التي سيبحث عنها مُحمِّل الإقلاع على القرص.
#define KERNEL_FILE_NAME L"\\GSODOS\\KERNEL.BIN"

// متغيرات عامة لخدمات UEFI
EFI_SYSTEM_TABLE *gST = NULL;
EFI_BOOT_SERVICES *gBS = NULL;

/**
 * دالة لتصفح وضع الرسومات (GOP - Graphics Output Protocol)
 * واختيار وضع يدعم دقة جيدة (مثلاً 800x600 أو أعلى) لبدء GSO-DOS.
 */
EFI_STATUS GsoSetGraphicsMode(void) {
    EFI_GRAPHICS_OUTPUT_PROTOCOL *gop;
    EFI_STATUS Status;
    UINTN i, SizeOfInfo;
    EFI_GRAPHICS_OUTPUT_MODE_INFORMATION *Info;

    // 1. البحث عن بروتوكول الإخراج الرسومي (GOP)
    Status = gBS->LocateProtocol(
        &gEfiGraphicsOutputProtocolGuid,
        NULL,
        (void**)&gop
    );
    if (EFI_ERROR(Status)) {
        Print(L"FATAL: Failed to locate GOP. Status: %r\n", Status);
        return Status;
    }

    // 2. تصفح الأوضاع المتاحة واختيار وضع مناسب (مثلاً: أعلى دقة متاحة)
    UINT32 BestMode = 0;
    UINTN MaxHres = 0;
    
    for (i = 0; i < gop->Mode->MaxMode; i++) {
        Status = gop->QueryMode(gop, i, &SizeOfInfo, &Info);
        if (EFI_ERROR(Status)) continue;

        if (Info->HorizontalResolution > MaxHres) {
            MaxHres = Info->HorizontalResolution;
            BestMode = i;
        }
    }

    // 3. تعيين أفضل وضع تم اختياره
    Status = gop->SetMode(gop, BestMode);
    if (EFI_ERROR(Status)) {
        Print(L"WARNING: Failed to set Best Graphics Mode. Status: %r\n", Status);
    } else {
        Print(L"INFO: Graphics Mode set to Mode %d (%dx%d).\n", 
              BestMode, gop->Mode->Info->HorizontalResolution, gop->Mode->Info->VerticalResolution);
    }

    return Status;
}

/**
 * الدالة الرئيسية: نقطة الدخول لتطبيق UEFI
 */
EFI_STATUS efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
    EFI_STATUS Status;
    UINTN MemoryMapSize = 0;
    EFI_MEMORY_DESCRIPTOR *MemoryMap = NULL;
    UINTN MapKey = 0;
    UINTN DescriptorSize = 0;
    UINT32 DescriptorVersion = 0;

    // تهيئة الخدمات الأساسية
    gST = SystemTable;
    gBS = SystemTable->BootServices;
    
    // إعداد واجهة الطباعة (Console) لـ GSO-DOS
    Print(L"GSO-DOS Bootloader (UEFI 64-bit) Starting...\n");
    Print(L"------------------------------------------\n");

    // 1. إعداد وضع الرسومات (GOP)
    GsoSetGraphicsMode();
    
    // 2. تحميل نواة GSO-DOS (Kernel)
    // *هذا الجزء يتطلب مكتبات إضافية (مثل File Protocol) لـ UEFI*
    // *لغرض التوضيح، سنفترض نجاح التحميل.*
    Print(L"Attempting to load kernel from: %s\n", KERNEL_FILE_NAME);
    // 
    
    // 3. الحصول على خريطة الذاكرة قبل إنهاء خدمات الإقلاع
    // نستخدم حلقة (loop) للحصول على الحجم الصحيح
    Status = gBS->GetMemoryMap(&MemoryMapSize, MemoryMap, &MapKey, &DescriptorSize, &DescriptorVersion);
    if (Status == EFI_BUFFER_TOO_SMALL) {
        // تخصيص المخزن المؤقت (Buffer) لخريطة الذاكرة
        MemoryMapSize += 2 * DescriptorSize; // إضافة حيز إضافي احتياطي
        Status = gBS->AllocatePool(EfiLoaderData, MemoryMapSize, (void**)&MemoryMap);
        if (EFI_ERROR(Status)) {
            Print(L"FATAL: Could not allocate memory for Memory Map.\n");
            return Status;
        }
        // الحصول على الخريطة
        Status = gBS->GetMemoryMap(&MemoryMapSize, MemoryMap, &MapKey, &DescriptorSize, &DescriptorVersion);
    }

    if (EFI_ERROR(Status)) {
        Print(L"FATAL: Failed to get Memory Map. Status: %r\n", Status);
        return Status;
    }
    
    // 4. إنهاء خدمات الإقلاع لـ UEFI (يجب أن يتم بعد الحصول على خريطة الذاكرة)
    Print(L"INFO: Exiting UEFI Boot Services and handing control to kernel...\n");
    Status = gBS->ExitBootServices(ImageHandle, MapKey);
    
    if (EFI_ERROR(Status)) {
        Print(L"FATAL: Failed to exit Boot Services. System Halted.\n");
        // إذا فشل الخروج، يجب إعادة الدخول في حلقة لا نهائية هنا
        while(1);
    }
    
    // 5. القفز إلى نواة GSO-DOS
    // (يجب أن يتم تنفيذ هذا الجزء بلغة Assembly بعد الخروج من خدمات UEFI)
    // void (*KernelEntry)(EFI_MEMORY_DESCRIPTOR*, UINTN, UINTN) = (void*)KERNEL_LOAD_ADDRESS;
    // KernelEntry(MemoryMap, MemoryMapSize, DescriptorSize); 
    
    // بما أننا في C، سنستخدم حلقة لا نهائية للمحاكاة بعد نجاح الخروج من UEFI
    Print(L"GSO-DOS Kernel loading... (Control passed)\n");
    while(1);
    
    return EFI_SUCCESS; // لن نصل إلى هنا في نظام حقيقي
}

