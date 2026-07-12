#include "image.h"

#include "framebuffer.h"

void thr_image_draw(uint32_t x,
                    uint32_t y,
                    uint32_t width,
                    uint32_t height,
                    const uint32_t *pixels)
{
    for (uint32_t py = 0; py < height; py++)
    {
        for (uint32_t px = 0; px < width; px++)
        {
            uint32_t color =
                pixels[py * width + px];

            /*
             * Si le pixel est totalement transparent,
             * on ne dessine rien.
             */
            if ((color >> 24) == 0)
                continue;

            thr_fb_put_pixel(
                x + px,
                y + py,
                color
            );
        }
    }
}
