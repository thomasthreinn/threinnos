#include "video.h"

#include "framebuffer.h"

void thr_video_init(struct limine_framebuffer *framebuffer)
{
    thr_fb_init(framebuffer);
}

void thr_video_clear(unsigned int color)
{
    thr_fb_clear(color);
}
