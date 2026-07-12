#include <stdio.h>

#include "image.h"
#include "writer.h"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage:\n");
        printf("./asset-converter input output\n");
        return 1;
    }

    Image image;

    if (image_load(argv[1], &image) != 0)
    {
        printf("Unable to load image.\n");
        return 1;
    }

    if (writer_generate(argv[2], &image) != 0)
    {
        printf("Unable to generate files.\n");

        image_free(&image);

        return 1;
    }

    image_free(&image);

    printf("Done.\n");

    return 0;
}
