#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "image.h"

#include <stdlib.h>
#include <string.h>

int image_load(const char *filename, Image *image)
{
    int width;
    int height;
    int channels;

    unsigned char *data =
        stbi_load(filename,
                  &width,
                  &height,
                  &channels,
                  STBI_rgb_alpha);

    if (data == NULL)
        return -1;

    image->width = (uint32_t)width;
    image->height = (uint32_t)height;

    image->pixels = malloc(width * height * sizeof(uint32_t));

    if (image->pixels == NULL)
    {
        stbi_image_free(data);
        return -1;
    }

    for (uint32_t i = 0; i < (uint32_t)(width * height); i++)
{
    uint8_t r = data[i * 4 + 0];
    uint8_t g = data[i * 4 + 1];
    uint8_t b = data[i * 4 + 2];
    uint8_t a = data[i * 4 + 3];

    image->pixels[i] =
        ((uint32_t)a << 24) |
        ((uint32_t)r << 16) |
        ((uint32_t)g << 8)  |
        (uint32_t)b;
}

stbi_image_free(data);

return 0;
}

void image_free(Image *image)
{
    free(image->pixels);

    image->pixels = NULL;

    image->width = 0;
    image->height = 0;
}
