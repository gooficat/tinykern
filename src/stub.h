#ifndef __STUB__H__
#define __STUB__H__

#include "kernel.h"
struct multiboot2_header {
    uint32_t magic;
    uint32_t architecture;
    uint32_t header_length;
    uint32_t checksum;
    struct {
        uint16_t type;
        uint16_t flags;
        uint32_t size;
    } end_tag;
};

#define MULTIBOOT2_MAGIC 0xE85250D6
#define MULTIBOOT2_ARCH_I386 0
#define MULTIBOOT2_HEADER_LENGTH sizeof(struct multiboot2_header)
#define MULTIBOOT2_CHECKSUM (-(MULTIBOOT2_MAGIC + MULTIBOOT2_ARCH_I386 + MULTIBOOT2_HEADER_LENGTH))


#endif