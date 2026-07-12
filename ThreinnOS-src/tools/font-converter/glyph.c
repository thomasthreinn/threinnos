#include "glyph.h"
#include "stb_truetype.h"

#include <stdlib.h>
#include <string.h>

int glyph_generate(Font *font,
                   uint32_t codepoint,
                   float size,
                   Glyph *glyph)
{
    float scale =
        stbtt_ScaleForPixelHeight(
            &font->info,
            size);

    int glyph_index =
        stbtt_FindGlyphIndex(
            &font->info,
            codepoint);

    int advance;
    int left_bearing;

    stbtt_GetGlyphHMetrics(
        &font->info,
        glyph_index,
        &advance,
        &left_bearing);

    int x0;
    int y0;
    int x1;
    int y1;

    stbtt_GetGlyphBitmapBox(
        &font->info,
        glyph_index,
        scale,
        scale,
        &x0,
        &y0,
        &x1,
        &y1);

    glyph->width  = x1 - x0;
    glyph->height = y1 - y0;

    glyph->offset_x = x0;
    glyph->offset_y = y0;

    glyph->advance =
        (int)(advance * scale);

    glyph->codepoint = codepoint;

    glyph->bitmap =
        stbtt_GetGlyphBitmap(
            &font->info,
            scale,
            scale,
            glyph_index,
            (int *)&glyph->width,
            (int *)&glyph->height,
            &glyph->offset_x,
            &glyph->offset_y);

    if (glyph->bitmap == NULL)
        return -1;

    return 0;
}

void glyph_free(Glyph *glyph)
{
    if (glyph->bitmap != NULL)
    {
        stbtt_FreeBitmap(
            glyph->bitmap,
            NULL);

        glyph->bitmap = NULL;
    }

    memset(glyph,
           0,
           sizeof(Glyph));
}
