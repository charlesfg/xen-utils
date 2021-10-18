#define _GNU_SOURCE
#include <sys/mman.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <err.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("invocation: %s <shell_cmd>\n", argv[0]);
    return 1;
  }

  char module_arg[100];
  sprintf(module_arg, "user_shellcmd_addr=%lu", (unsigned long)argv[1]);

  // load module
  int mod_fd = open("test.ko", O_RDONLY);
  if (mod_fd == -1)
    err(1, "open module file");
  int init_res = syscall(__NR_finit_module, mod_fd, module_arg, 0);
  if (init_res)
    err(1, "finit_module");

  puts("press enter to continue");
  getchar();

  // create the PUD
  void *pud_dummy_page = mmap((void*)0x600000000000ULL, 0x1000, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_FIXED|MAP_LOCKED, -1, 0);
  if (pud_dummy_page != (void*)0x600000000000ULL)
    err(1, "mmap PUD dummy page");

  // unload the module, creating the memory mappings
  if (syscall(__NR_delete_module, "test", O_NONBLOCK))
    perror("delete_module");
}
