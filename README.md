# GSO-OS V2.0.0: The Modern 64-bit DOS

## 🚀 Overview

GSO-OS is an open-source project to revive and modernize the classic **GSO-OS** operating system, transitioning it from the old 16-bit BIOS-based architecture to a modern **64-bit** **UEFI**-based one.

The goal is to build an OS that offers full compatibility with old DOS programs (`.COM`, old `.EXE`) while supporting modern 64-bit applications (`.ELF`, `.GXE`).

## ⚙️ Specifications and Goals

| Feature | Description | Development Status |
| :--- | :--- | :--- |
| **Core Architecture** | 64-bit (Long Mode) | Complete |
| **Bootloader** | UEFI Native (`gsoboot.efi` written in C) | Complete |
| **Kernel** | Custom Kernel written in C/C++ | In Development |
| **Compatibility Layer (GSO-EXEC)** | Loads and manages `.COM`, `.EXE`, `.SYS`, `.DLL`, `.ELF`, and `.GXE` | In Development |
| **Target Hardware** | Intel and AMD processors (x86-64) | Complete |

## 🏗️ Project Structure

* **`boot/`**: Contains the UEFI Bootloader code.
* **`kernel/`**: The core GSO-OS Kernel.
* **`kernel/compatibility/`**: The **GSO-EXEC** layer for executable handling.
* **`cmd/`**: Classic DOS commands (being adapted for 64-bit).

## 🛠️ Building

GSO-OS requires a **Cross-Compiler** targeting x86-64 (e.g., `x86_64-w64-mingw32-gcc`):

1.  **Initialize:** (Ensure tools are installed).
2.  **Build:** Navigate to the root (`gso-dos`) and run:
    ```bash
    make
    ```

## 🤝 Contributing

We welcome contributions!

1.  Clone the repository.
2.  **Switch to the development branch:** `git checkout development`
3.  **Create a new branch** for your feature/fix.
4.  **Submit a Pull Request** to the **`development`** branch.

---

* **Author:** adembenarfa175-code
* **License:** MIT License

