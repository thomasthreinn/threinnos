#include "writer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADER_GUARD "THR_GENERATED_LOGO_H"

static int write_logo_header(FILE *header,
                             const Image *image)
{
    fprintf(header,
        "#ifndef %s\n"
        "#define %s\n\n",
        HEADER_GUARD,
        HEADER_GUARD);

    fprintf(header,
        "#include <stdint.h>\n\n");

    fprintf(header,
        "#define THR_LOGO_WIDTH  %u\n",
        image->width);

    fprintf(header,
        "#define THR_LOGO_HEIGHT %u\n\n",
        image->height);

    fprintf(header,
        "extern const uint32_t thr_logo_pixels[%u];\n\n",
        image->width * image->height);

    fprintf(header,
        "#endif\n");

    return 0;
}

static int write_logo_source_begin(FILE *source)
{
    fprintf(source,
        "#include \"logo.h\"\n\n");

    fprintf(source,
        "const uint32_t thr_logo_pixels[THR_LOGO_WIDTH * THR_LOGO_HEIGHT] =\n");
    fprintf(source, "{\n");

    return 0;
}

static int write_logo_pixels(FILE *source,
                             const Image *image)
{
    uint32_t count = image->width * image->height;

    for (uint32_t i = 0; i < count; i++)
    {
        fprintf(source, "    0x%08X,", image->pixels[i]);

        /* Retour à la ligne toutes les 8 valeurs */
        if ((i + 1) % 8 == 0)
        {
            fprintf(source, "\n");
        }
    }

    /* Si la dernière ligne n'était pas complète */
    if (count % 8 != 0)
    {
        fprintf(source, "\n");
    }

    return 0;
}

static int write_logo_source_end(FILE *source)
{
    fprintf(source, "};\n");

    return 0;
}

static int write_manifest(FILE *manifest)
{
    fprintf(manifest,
        "#ifndef THR_GENERATED_MANIFEST_H\n"
        "#define THR_GENERATED_MANIFEST_H\n\n");

    fprintf(manifest,
        "#include \"logo.h\"\n\n");

    fprintf(manifest,
        "#endif\n");

    return 0;
}

int writer_generate(const char *basename,
                    const Image *image)
{
    char header_name[512];
    char source_name[512];
    char manifest_name[512];

    snprintf(header_name,
             sizeof(header_name),
             "%s.h",
             basename);

    snprintf(source_name,
             sizeof(source_name),
             "%s.c",
             basename);

    strcpy(manifest_name, "manifest.h");

    FILE *header = fopen(header_name, "w");

    if (!header)
        return -1;

    FILE *source = fopen(source_name, "w");

    if (!source)
    {
        fclose(header);
        return -1;
    }

    FILE *manifest = fopen(manifest_name, "w");

    if (!manifest)
    {
        fclose(header);
        fclose(source);
        return -1;
    }

    write_logo_header(header, image);
    write_logo_source_begin(source);

    write_logo_pixels(source, image);

    write_logo_source_end(source);

    write_manifest(manifest);

    fclose(header);
    fclose(source);
    fclose(manifest);

    return 0;
}
