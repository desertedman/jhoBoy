#pragma once

#include <array>
#include <cstdint>

enum r8 {
  REG_B,
  REG_C,
  REG_D,
  REG_E,
  REG_H,
  REG_L,
  REG_HL_PTR,
  REG_A,
};

enum r16 {
  REG_BC,
  REG_DE,
  REG_HL,
  REG_SP,
};

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

struct OpcodeParameters {
  uint8_t destination;
  uint8_t source;
};

class CPU {
public:
  void printOpcodeBits(int opcode = 0);
  void fetchOpcode(int opcode);
  void decodeOpcode();
  void executeOpcode();

  std::array<uint8_t, 0xFFFF> memoryMap;
  Registers registers;

private:
  uint8_t readR8(uint8_t source);
  void writeR8(uint8_t destination);
  void loadR8(uint8_t destination, uint8_t source);

  uint8_t mOpcode;
  OpcodeParameters parameters;
};
