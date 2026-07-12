#ifndef THR_IMAGE_H
#define THR_IMAGE_H

#include <stdint.h>

/*
 * Affiche une image RGBA32.
 *
 * image  : tableau de pixels 32 bits
 * width  : largeur de l'image
 * height : hauteur de l'image
 */
void thr_image_draw(uint32_t x,
                    uint32_t y,
                    const uint32_t *image,
                    uint32_t width,
                    uint32_t height);

/*
 * Centre automatiquement une image sur l'écran.
 */
void thr_image_draw_center(const uint32_t *image,
                           uint32_t width,
                           uint32_t height);

#endif
