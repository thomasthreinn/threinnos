#include "writer.h"

#include <stdio.h>
#include <stdint.h>

static int write_header(FILE *header,
                        const Glyph *glyphs,
                        uint32_t glyph_count)
{
    fprintf(header,
    "#ifndef THR_GENERATED_FONT_H\n"
    "#define THR_GENERATED_FONT_H\n\n");

fprintf(header,
    "#include <stdint.h>\n\n");

fprintf(header,
    "typedef struct\n"
    "{\n"
    "    uint32_t codepoint;\n"
    "    uint16_t width;\n"
    "    uint16_t height;\n"
    "    int16_t offset_x;\n"
    "    int16_t offset_y;\n"
    "    int16_t advance;\n"
    "    const uint8_t *bitmap;\n"
    "} ThrFontGlyph;\n\n");

fprintf(header,
    "#define THR_FONT_GLYPH_COUNT %u\n\n",
    glyph_count);

fprintf(header,
    "extern const ThrFontGlyph "
    "thr_font_glyphs[THR_FONT_GLYPH_COUNT];\n\n");

fprintf(header,
    "#endif\n");

    return 0;
}

static int write_source(FILE *source,
                        const Glyph *glyph)
{
    fprintf(source,
        "#include \"font.h\"\n\n");

    fprintf(source,
        "const uint8_t thr_glyph_bitmap[%u] =\n",
        glyph->width * glyph->height);

    fprintf(source, "{\n");

    uint32_t count = glyph->width * glyph->height;

    for (uint32_t i = 0; i < count; i++)
    {
        fprintf(source,
                "    %3u,",
                glyph->bitmap[i]);

        if ((i + 1) % 16 == 0)
            fprintf(source, "\n");
    }

    if (count % 16 != 0)
        fprintf(source, "\n");

    fprintf(source, "};\n");

    return 0;
}

int writer_generate(const char *basename,
                    const Glyph *glyphs,
                    uint32_t glyph_count)
{
    char header_name[512];
    char source_name[512];

    snprintf(header_name,
             sizeof(header_name),
             "%s.h",
             basename);

    snprintf(source_name,
             sizeof(source_name),
             "%s.c",
             basename);

    FILE *header = fopen(header_name, "w");

    if (header == NULL)
        return -1;

    FILE *source = fopen(source_name, "w");

    if (source == NULL)
    {
        fclose(header);
        return -1;
    }

    write_header(header,
             glyphs,
             glyph_count);
    write_source(source, &glyphs[0]);

    fclose(header);
    fclose(source);

    return 0;
}
