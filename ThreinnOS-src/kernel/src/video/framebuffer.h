#ifndef THR_FRAMEBUFFER_H
#define THR_FRAMEBUFFER_H

#include <stdint.h>
#include <stddef.h>

#include <limine.h>

void thr_fb_init(struct limine_framebuffer *framebuffer);

void thr_fb_put_pixel(uint32_t x,
                      uint32_t y,
                      uint32_t color);

void thr_fb_clear(uint32_t color);

uint32_t thr_fb_width(void);

uint32_t thr_fb_height(void);

#endif
