#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/syscalls.h>

#include "hypercall.h"

SYSCALL_DEFINE4(hypercall, unsigned long, id, unsigned long, cmd, unsigned long, arg, unsigned long, sched)
{
    uint64_t ret;
    asm volatile (
            /*
            "pushq %%rax\n\t"
            "pushq %%rbx\n\t"
            "pushq %%rcx\n\t"
            "pushq %%rdx\n\t"
            */
            "movq %1, %%rax\n\t"
            "movq %2, %%rbx\n\t"
            "movq %3, %%rcx\n\t"
            "movq %4, %%rdx\n\t"
            "nop\n\t"
            "movq %%rax, %0\n\t"
            /*
            "popq %%rdx\n\t"
            "popq %%rcx\n\t"
            "popq %%rbx\n\t"
            "popq %%rax\n\t"
            */
            :"=r"(ret)
            :"r"(id), "r"(cmd), "r"(arg), "r"(sched)
            :
            );
    return ret;
}
