#include "display.h"

// Global pointer to the framebuffer details
static gso_graphics_info_t *g_gop_info = NULL;

void gso_display_init(gso_graphics_info_t *gop_info) {
    if (!gop_info) return;
    
    g_gop_info = gop_info;
    
    // Placeholder print to confirm initialization
    // (This requires the kernel print function to be ready, but this is the intent)
    // gso_print("GUI: Display initialized at %dx%d, Base: 0x%lx\n", gop_info->width, gop_info->height, gop_info->frame_buffer_base);
}

void gso_draw_pixel(uint32_t x, uint32_t y, uint32_t color) {
    if (!g_gop_info || x >= g_gop_info->width || y >= g_gop_info->height) {
        return;
    }

    // Calculate the address in the VRAM (Frame Buffer)
    // Formula: Base + (Y * Pitch) + (X * (BPP/8))
    uint8_t *fb_ptr = (uint8_t*)g_gop_info->frame_buffer_base;
    uint32_t offset = (y * g_gop_info->pitch) + (x * (g_gop_info->bpp / 8));
    
    // Assuming 32-bit color depth (ARGB)
    *(uint32_t*)(fb_ptr + offset) = color;
}

void gso_fill_screen(uint32_t color) {
    if (!g_gop_info) return;
    
    for (uint32_t y = 0; y < g_gop_info->height; y++) {
        for (uint32_t x = 0; x < g_gop_info->width; x++) {
            gso_draw_pixel(x, y, color);
        }
    }
}

