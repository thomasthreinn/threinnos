#ifndef THR_VIDEO_H
#define THR_VIDEO_H

#include <limine.h>

void thr_video_init(struct limine_framebuffer *framebuffer);

void thr_video_clear(unsigned int color);

#endif
