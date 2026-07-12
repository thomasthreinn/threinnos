#include "draw.h"

#include "framebuffer.h"

void thr_draw_pixel(uint32_t x,
                    uint32_t y,
                    uint32_t color)
{
    thr_fb_put_pixel(x, y, color);
}

void thr_draw_hline(uint32_t x,
                    uint32_t y,
                    uint32_t width,
                    uint32_t color)
{
    for (uint32_t i = 0; i < width; i++)
    {
        thr_draw_pixel(x + i, y, color);
    }
}

void thr_draw_vline(uint32_t x,
                    uint32_t y,
                    uint32_t height,
                    uint32_t color)
{
    for (uint32_t i = 0; i < height; i++)
    {
        thr_draw_pixel(x, y + i, color);
    }
}

void thr_draw_rect(uint32_t x,
                   uint32_t y,
                   uint32_t width,
                   uint32_t height,
                   uint32_t color)
{
    thr_draw_hline(x, y, width, color);

    thr_draw_hline(x, y + height - 1, width, color);

    thr_draw_vline(x, y, height, color);

    thr_draw_vline(x + width - 1, y, height, color);
}

void thr_draw_fill_rect(uint32_t x,
                        uint32_t y,
                        uint32_t width,
                        uint32_t height,
                        uint32_t color)
{
    for (uint32_t yy = 0; yy < height; yy++)
    {
        thr_draw_hline(x, y + yy, width, color);
    }
}
