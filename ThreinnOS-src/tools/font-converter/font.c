#define STB_TRUETYPE_IMPLEMENTATION
#include "stb_truetype.h"

#include "font.h"

#include <stdio.h>
#include <stdlib.h>

int font_load(const char *filename,
              Font *font)
{
    FILE *file = fopen(filename, "rb");

    if (file == NULL)
    {
        return -1;
    }

    fseek(file, 0, SEEK_END);

    font->size = (uint32_t)ftell(file);

    rewind(file);

    font->buffer =
        malloc(font->size);

    if (font->buffer == NULL)
    {
        fclose(file);
        return -1;
    }

    if (fread(font->buffer,
              1,
              font->size,
              file) != font->size)
    {
        free(font->buffer);

        fclose(file);

        return -1;
    }

    fclose(file);

    if (!stbtt_InitFont(
            &font->info,
            font->buffer,
            0))
    {
        free(font->buffer);

        return -1;
    }

    return 0;
}

void font_free(Font *font)
{
    if (font->buffer != NULL)
    {
        free(font->buffer);

        font->buffer = NULL;
    }

    font->size = 0;
}
