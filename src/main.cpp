#include "CPU.h"

int main() {
  CPU cpu;

  cpu.fetchOpcode(0x7E);
  cpu.decodeOpcode();
  cpu.printOpcodeBits();

  return 0;
}
