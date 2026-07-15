#include <stddef.h>
#include <stdint.h>
#include "stub.h"


__attribute__((section(".bss"))) uint8_t kernel_stack[16384];
__attribute__((section(".text"))) void kernel_main(uint32_t magic, uint32_t addr);

__attribute__((section(".text"))) void _start(void) {
    __asm__ __volatile__(
        "cli\n"
        "movl %0, %%esp\n"
        "call kernel_main\n"
        :
        : "r"(kernel_stack + sizeof(kernel_stack))
    );
}

void kernel_main(uint32_t magic, [[maybe_unused]] uint32_t addr) {
    if (magic != MULTIBOOT2_MAGIC) {
        for (;;) {
            __asm__ __volatile__("hlt");
        }
    }

    for (;;) {
        __asm__ __volatile__("hlt");
    }
}
