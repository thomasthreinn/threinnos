#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <limine.h>

#include "kernel/boot.h"

/* Limine base revision */
__attribute__((used, section(".limine_requests")))
static volatile uint64_t limine_base_revision[] = LIMINE_BASE_REVISION(6);

/* Framebuffer request */
__attribute__((used, section(".limine_requests")))
static volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST_ID,
    .revision = 0
};

/* Limine request markers */
__attribute__((used, section(".limine_requests_start")))
static volatile uint64_t limine_requests_start_marker[] = LIMINE_REQUESTS_START_MARKER;

__attribute__((used, section(".limine_requests_end")))
static volatile uint64_t limine_requests_end_marker[] = LIMINE_REQUESTS_END_MARKER;

/* CPU halt */
static void hcf(void)
{
    for (;;) {
        asm volatile ("hlt");
    }
}

/* ThreinnOS entry point */
void kmain(void)
{
    /* Check Limine revision */
    if (!LIMINE_BASE_REVISION_SUPPORTED(limine_base_revision))
        hcf();

    /* Check framebuffer */
    if (framebuffer_request.response == NULL ||
        framebuffer_request.response->framebuffer_count < 1)
        hcf();

    /* Get framebuffer */
    struct limine_framebuffer *framebuffer =
        framebuffer_request.response->framebuffers[0];

    /* Hand over to ThreinnOS */
    thr_boot(framebuffer);

    /* Never return */
    hcf();
}
