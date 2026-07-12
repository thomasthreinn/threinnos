#include "writer.h"

#include <stdio.h>

static int write_header(FILE *file,
                        const Image *image)
{
    fprintf(file,
"#ifndef THR_GENERATED_LOGO_H\n"
"#define THR_GENERATED_LOGO_H\n\n"
"#include <stdint.h>\n\n"
"#define THR_LOGO_WIDTH %u\n"
"#define THR_LOGO_HEIGHT %u\n\n"
"extern const uint32_t thr_logo_pixels[];\n\n"
"#endif\n",
image->width,
image->height);

    return 0;
}

static int write_source(FILE *file,
                        const Image *image)
{
    fprintf(file,
"#include \"logo.h\"\n\n");

    fprintf(file,
"const uint32_t thr_logo_pixels[] = {\n");

    uint32_t count = image->width * image->height;

    for (uint32_t i = 0; i < count; i++)
    {
        fprintf(file,
"0x%08X,",
image->pixels[i]);

        if ((i + 1) % 8 == 0)
            fprintf(file, "\n");
    }

    fprintf(file,
"\n};\n");

    return 0;
}

int writer_generate(const char *basename,
                    const Image *image)
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

    FILE *header =
        fopen(header_name, "w");

    if (!header)
        return -1;

    FILE *source =
        fopen(source_name, "w");

    if (!source)
    {
        fclose(header);
        return -1;
    }

    write_header(header, image);

    write_source(source, image);

    fclose(header);
    fclose(source);

    return 0;
}
