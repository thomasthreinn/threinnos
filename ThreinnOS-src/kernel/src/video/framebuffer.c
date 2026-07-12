#include "framebuffer.h"

static struct limine_framebuffer *g_framebuffer = NULL;

void thr_fb_init(struct limine_framebuffer *framebuffer)
{
    g_framebuffer = framebuffer;
}

uint32_t thr_fb_width(void)
{
    return g_framebuffer->width;
}

uint32_t thr_fb_height(void)
{
    return g_framebuffer->height;
}

void thr_fb_put_pixel(uint32_t x,
                      uint32_t y,
                      uint32_t color)
{
    /* Framebuffer non initialisé */
    if (g_framebuffer == NULL)
        return;

    /* Protection contre les écritures hors écran */
    if (x >= g_framebuffer->width)
        return;

    if (y >= g_framebuffer->height)
        return;

    volatile uint32_t *fb = g_framebuffer->address;

    fb[y * (g_framebuffer->pitch / 4) + x] = color;
}

void thr_fb_clear(uint32_t color)
{
    if (g_framebuffer == NULL)
        return;

    for (size_t y = 0; y < g_framebuffer->height; y++)
    {
        for (size_t x = 0; x < g_framebuffer->width; x++)
        {
            thr_fb_put_pixel(x, y, color);
        }
    }
}
