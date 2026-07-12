#ifndef THR_FONT_H
#define THR_FONT_H

#include <stdint.h>
#include "stb_truetype.h"

typedef struct
{
    unsigned char *buffer;

    uint32_t size;

    stbtt_fontinfo info;

} Font;

int font_load(const char *filename,
              Font *font);

void font_free(Font *font);

#endif
