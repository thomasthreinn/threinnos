#ifndef THR_IMAGE_H
#define THR_IMAGE_H

#include <stdint.h>

void thr_image_draw(uint32_t x,
                    uint32_t y,
                    uint32_t width,
                    uint32_t height,
                    const uint32_t *pixels);

#endif
