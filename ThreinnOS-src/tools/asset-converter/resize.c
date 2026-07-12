#include "resize.h"

#include <stdlib.h>
#include <string.h>

int image_resize(Image *image,
                 uint32_t new_width,
                 uint32_t new_height)
{
    uint32_t *new_pixels =
        malloc(new_width * new_height * sizeof(uint32_t));

    if (!new_pixels)
        return -1;

    for (uint32_t y = 0; y < new_height; y++)
    {
        uint32_t src_y =
            (y * image->height) / new_height;

        for (uint32_t x = 0; x < new_width; x++)
        {
            uint32_t src_x =
                (x * image->width) / new_width;

            new_pixels[y * new_width + x] =
                image->pixels[src_y * image->width + src_x];
        }
    }

    free(image->pixels);

    image->pixels = new_pixels;
    image->width = new_width;
    image->height = new_height;

    return 0;
}
