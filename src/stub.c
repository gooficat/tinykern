#include "stub.h"
#include <stdint.h>

__attribute__((section(".multiboot"))) uint32_t mb_header[] = {
    MULTIBOOT2_MAGIC,
    MULTIBOOT2_ARCH_I386,
    MULTIBOOT2_HEADER_LENGTH,
    MULTIBOOT2_CHECKSUM,
    // end tag
    0,
    0,
    0,
};