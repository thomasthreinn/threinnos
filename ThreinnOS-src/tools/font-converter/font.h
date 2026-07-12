#ifndef THR_FONT_H
#define THR_FONT_H

#include <stdint.h>

typedef struct stbtt_fontinfo stbtt_fontinfo;

typedef struct
{
    unsigned char *buffer;

    uint32_t size;

    stbtt_fontinfo info;

} Font;

/*
 * Charge entièrement une police en mémoire
 * puis initialise stb_truetype.
 */
int font_load(const char *filename,
              Font *font);

/*
 * Libère la mémoire occupée par la police.
 */
void font_free(Font *font);

#endif
