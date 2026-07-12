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

    memcpy(image->pixels,
           data,
           width * height * sizeof(uint32_t));

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
