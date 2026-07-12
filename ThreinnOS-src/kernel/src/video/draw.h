#ifndef THR_DRAW_H
#define THR_DRAW_H

#include <stdint.h>

void thr_draw_pixel(uint32_t x,
                    uint32_t y,
                    uint32_t color);

void thr_draw_hline(uint32_t x,
                    uint32_t y,
                    uint32_t width,
                    uint32_t color);

void thr_draw_vline(uint32_t x,
                    uint32_t y,
                    uint32_t height,
                    uint32_t color);

void thr_draw_rect(uint32_t x,
                   uint32_t y,
                   uint32_t width,
                   uint32_t height,
                   uint32_t color);

void thr_draw_fill_rect(uint32_t x,
                        uint32_t y,
                        uint32_t width,
                        uint32_t height,
                        uint32_t color);

#endif
