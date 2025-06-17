#include "CPU.h"
#include <cstdint>

int main() {
  CPU cpu;

  uint8_t opcode = 0x41; // Load C into B; Read C, write into B
  cpu.registers.bc.low = 200;
  cpu.fetchOpcode(opcode);
  cpu.decodeOpcode();
  cpu.executeOpcode();
  // cpu.printOpcodeBits();

  return 0;
}
