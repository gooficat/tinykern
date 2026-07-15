#include <stddef.h>
#include <stdint.h>
#include "stub.h"
#include "kernel.h"


__attribute__((section(".bss"))) uint8_t kernel_stack[KERNEL_STACK_SIZE];
__attribute__((section(".text"))) void kernel_main(uint32_t magic, uint32_t addr);


void kernel_main(uint32_t magic, [[maybe_unused]] uint32_t addr) {
    for (;;) {
        __asm__ __volatile__("hlt");
    }
}
