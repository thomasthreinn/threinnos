#ifndef THR_GLYPH_H
#define THR_GLYPH_H

#include <stdint.h>

#include "font.h"

typedef struct
{
    uint32_t codepoint;

    uint32_t width;
    uint32_t height;

    int32_t offset_x;
    int32_t offset_y;

    int32_t advance;

    unsigned char *bitmap;

} Glyph;

/*
 * Génère le bitmap d'un caractère.
 */
int glyph_generate(Font *font,
                   uint32_t codepoint,
                   float size,
                   Glyph *glyph);

/*
 * Libère la mémoire du bitmap.
 */
void glyph_free(Glyph *glyph);

#endif
