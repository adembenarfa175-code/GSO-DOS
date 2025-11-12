#ifndef GSO_DISPLAY_H
#define GSO_DISPLAY_H

#include <stdint.h>
#include <stddef.h>

// Structure to hold information about the graphics mode (passed from bootloader)
typedef struct {
    uint64_t frame_buffer_base; // Base address of the VRAM
    uint32_t width;             // Screen width (pixels)
    uint32_t height;            // Screen height (pixels)
    uint32_t pitch;             // Bytes per line
    uint8_t  bpp;               // Bits Per Pixel (e.g., 32 for ARGB)
} gso_graphics_info_t;

// Initializes the graphical display using GOP data
void gso_display_init(gso_graphics_info_t *gop_info);

// Simple pixel drawing function
void gso_draw_pixel(uint32_t x, uint32_t y, uint32_t color);

// Simple fill screen function (for testing)
void gso_fill_screen(uint32_t color);

#endif // GSO_DISPLAY_H

