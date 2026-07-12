#ifndef IMAGE_H
#define IMAGE_H

#include <stdint.h>

typedef struct
{
    uint32_t width;
    uint32_t height;
    uint32_t *pixels;

} Image;

int image_load(const char *filename, Image *image);

void image_free(Image *image);

#endif
