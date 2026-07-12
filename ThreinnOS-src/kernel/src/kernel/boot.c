#include "boot.h"

#include "../video/video.h"
#include "../video/logo.h"
#include "../video/color.h"

void thr_boot(struct limine_framebuffer *framebuffer)
{
    /* Initialisation vidéo */
    thr_video_init(framebuffer);

    /* Fond officiel */
    thr_video_clear(THR_COLOR_BACKGROUND);

    /* Logo ThreinnOS */
    thr_logo_show();

    /*
     * Modules suivants
     *
     * thr_logger_init();
     * thr_memory_init();
     * thr_scheduler_init();
     * ...
     */
}
