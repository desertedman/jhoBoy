#include <array>
#include <cstdint>
#include <cstdio>

union RegisterPair {
  struct {
    uint8_t low;
    uint8_t high;
  };

  uint16_t value;
};

struct Registers {
  RegisterPair af; // high = a, low = f
  RegisterPair bc;
  RegisterPair de;
  RegisterPair hl;
  uint16_t sp; // stack pointer
  uint16_t pc; // program counter
};

class CPU {
public:
  std::array<uint8_t, 0xFFFF> memoryMap;
  Registers registers;
};

int main() {
  CPU cpu;
  cpu.registers.af.value = 0x1234;

  printf("A = %02X, F = %02X\n", cpu.registers.af.high,
         cpu.registers.af.low); // A = 12, F = 34

  return 0;
}
