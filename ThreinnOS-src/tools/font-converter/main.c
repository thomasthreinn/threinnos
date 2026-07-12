#include <stdio.h>

#include "config.h"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("ThreinnOS Font Converter %s\n\n",
               THR_FONT_CONVERTER_VERSION);

        printf("Usage:\n");
        printf("    ./font-converter <input_font> <output_directory>\n\n");

        printf("Example:\n");
        printf("    ./font-converter ../../assets/font/JetBrainsMono-Regular.ttf ");
        printf("../../kernel/src/video/generated\n");

        return 1;
    }

    printf("Input : %s\n", argv[1]);
    printf("Output: %s\n", argv[2]);

    printf("\n");

    printf("Font converter initialized successfully.\n");

    return 0;
}
