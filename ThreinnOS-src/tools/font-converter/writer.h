#ifndef WRITER_H
#define WRITER_H

#include "glyph.h"

int writer_generate(const char *basename,
                    const Glyph *glyphs,
                    uint32_t glyph_count);

#endif
