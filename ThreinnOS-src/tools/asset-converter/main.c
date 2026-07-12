#include <stdio.h>

#include "image.h"
#include "writer.h"
#include "config.h"
#include "resize.h"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("ThreinnOS Asset Converter\n\n");
        printf("Usage:\n");
        printf("    ./asset-converter <input_image> <output_base>\n\n");
        printf("Example:\n");
        printf("    ./asset-converter logo.png ../../kernel/src/video/generated/logo\n");

        return 1;
    }

    Image image;

    if (image_load(argv[1], &image) != 0)
    {
        printf("Error: unable to load '%s'\n", argv[1]);
        return 1;
    }

    if (image_resize(&image,
                 THR_BOOT_LOGO_WIDTH,
                 THR_BOOT_LOGO_HEIGHT) != 0)
{
    printf("Unable to resize image.\n");

    image_free(&image);

    return 1;
}

    printf("Image loaded successfully.\n");
    printf("Resolution : %ux%u\n", image.width, image.height);

    if (writer_generate(argv[2], &image) != 0)
    {
        printf("Error: unable to generate output files.\n");

        image_free(&image);

        return 1;
    }

    image_free(&image);

    printf("Generation completed successfully.\n");

    return 0;
}
