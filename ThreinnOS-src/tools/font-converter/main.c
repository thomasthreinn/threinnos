#include <stdio.h>

#include "config.h"
#include "font.h"
#include "glyph.h"
#include "writer.h"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("ThreinnOS Font Converter %s\n\n",
               THR_FONT_CONVERTER_VERSION);

        printf("Usage:\n");
        printf("    ./font-converter <input_font> <output_base>\n\n");

        printf("Example:\n");
        printf("    ./font-converter ");
        printf("../../assets/font/JetBrainsMono-Regular.ttf ");
        printf("../../kernel/src/video/generated/font\n");

        return 1;
    }

    Font font;
    Glyph glyphs[95];

    printf("Loading font...\n");

    if (font_load(argv[1], &font) != 0)
    {
        printf("Error: unable to load font.\n");
        return 1;
    }

    printf("Generating ASCII glyphs...\n");

for (uint32_t i = 0; i < 95; i++)
{
    if (glyph_generate(&font,
                       i + 32,
                       32.0f,
                       &glyphs[i]) != 0)
    {
        printf("Error: unable to generate ASCII glyph %u.\n",
               i + 32);

        while (i > 0)
        {
            i--;
            glyph_free(&glyphs[i]);
        }

        font_free(&font);

        return 1;
    }
}

    printf("Writing generated files...\n");

    if (writer_generate(argv[2],
                    glyphs,
                    95) != 0)
    {
        printf("Error: unable to write generated files.\n");

        for (uint32_t i = 0; i < 95; i++)
{
    glyph_free(&glyphs[i]);
}
        font_free(&font);

        return 1;
    }

    for (uint32_t i = 0; i < 95; i++)
{
    glyph_free(&glyphs[i]);
}
    font_free(&font);

    printf("\n");
    printf("Generation completed successfully.\n");

    return 0;
}
