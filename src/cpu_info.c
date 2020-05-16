#include <stdint.h>
#include <string.h>
void *cpu_name(char *string_buffer) {
  /* returns cpu name
   * assumes string_buffer can hold at 13 32-bit words */
  uint32_t cpu_string[13] = {0};
  asm __volatile__("mov $0x80000002 , %eax");
  asm __volatile__("cpuid");
  asm __volatile__("mov %%eax, %0\n\t" : "=r"(cpu_string[0]));
  asm __volatile__("mov %%ebx, %0\n\t" : "=r"(cpu_string[1]));
  asm __volatile__("mov %%ecx, %0\n\t" : "=r"(cpu_string[2]));
  asm __volatile__("mov %%edx, %0\n\t" : "=r"(cpu_string[3]));
  asm __volatile__("mov $0x80000003 , %eax");
  asm __volatile__("cpuid");
  asm __volatile__("mov %%eax, %0\n\t" : "=r"(cpu_string[4]));
  asm __volatile__("mov %%ebx, %0\n\t" : "=r"(cpu_string[5]));
  asm __volatile__("mov %%ecx, %0\n\t" : "=r"(cpu_string[6]));
  asm __volatile__("mov %%edx, %0\n\t" : "=r"(cpu_string[7]));
  asm __volatile__("mov $0x80000004 , %eax");
  asm __volatile__("cpuid");
  asm __volatile__("mov %%eax, %0\n\t" : "=r"(cpu_string[8]));
  asm __volatile__("mov %%ebx, %0\n\t" : "=r"(cpu_string[9]));
  asm __volatile__("mov %%ecx, %0\n\t" : "=r"(cpu_string[10]));
  asm __volatile__("mov %%edx, %0\n\t" : "=r"(cpu_string[11]));
  strcpy(string_buffer, (char *)cpu_string);
}
