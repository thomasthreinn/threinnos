#include <stdint.h>

#include "image.h"
#include "draw.h"
#include "framebuffer.h"

void thr_image_draw(uint32_t x,
                    uint32_t y,
                    const uint32_t *image,
                    uint32_t width,
                    uint32_t height)
{
    for (uint32_t yy = 0; yy < height; yy++)
    {
        for (uint32_t xx = 0; xx < width; xx++)
        {
            uint32_t pixel = image[(yy * width) + xx];

            /*
             * Pour la V1 :
             * 0x00000000 = pixel transparent.
             */
            if (pixel != 0x00000000)
            {
                thr_draw_pixel(
                    x + xx,
                    y + yy,
                    pixel
                );
            }
        }
    }
}

void thr_image_draw_center(const uint32_t *image,
                           uint32_t width,
                           uint32_t height)
{
    uint32_t x = (thr_fb_width() - width) / 2;
    uint32_t y = (thr_fb_height() - height) / 2;

    thr_image_draw(
        x,
        y,
        image,
        width,
        height
    );
}
