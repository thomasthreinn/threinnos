#include "logo.h"

#include "image.h"
#include "framebuffer.h"

#include "generated/logo.h"

void thr_logo_show(void)
{
    uint32_t x =
        (thr_fb_width() - THR_LOGO_WIDTH) / 2;

    uint32_t y =
        (thr_fb_height() - THR_LOGO_HEIGHT) / 2;

    thr_image_draw(
        x,
        y,
        THR_LOGO_WIDTH,
        THR_LOGO_HEIGHT,
        thr_logo_pixels
    );
}

