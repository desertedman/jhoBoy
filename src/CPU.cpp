#include "CPU.h"
#include <bitset>
#include <cstdint>
#include <iostream>
#include <stdexcept>

void CPU::printOpcodeBits(int opcode) {
  if (opcode == 0) {
    std::cout << "Opcode: " << (std::bitset<8>)mOpcode << std::endl;
    std::cout << "Destination: " << (std::bitset<3>)parameters.destination
              << std::endl;
    std::cout << "Source: " << (std::bitset<3>)parameters.source << std::endl;
  }

  else {
    std::cout << "Opcode: " << (std::bitset<8>)opcode << std::endl;
  }
}

void CPU::fetchOpcode(int opcode) { mOpcode = opcode; }

void CPU::decodeOpcode() {
  parameters.destination = (mOpcode >> 3) & 0b111;
  parameters.source = mOpcode & 0b111;
}

void CPU::executeOpcode() {
  if (mOpcode >= 0x40 && mOpcode <= 0x70 && mOpcode != 0x76) {
    std::cout << "Load instruction called\n";
    loadR8(parameters.destination, parameters.source);
  }
}

uint8_t CPU::readR8(uint8_t source) {
  switch (source) {
  case REG_B:
    return registers.bc.high;
    break;
  case REG_C:
    return registers.bc.low;
    break;
  case REG_D:
    return registers.de.high;
    break;
  case REG_E:
    return registers.de.low;
    break;
  case REG_H:
    return registers.hl.high;
    break;
  case REG_L:
    return registers.hl.low;
    break;
  case REG_HL_PTR:
    return registers.hl.value;
    break;
  default:
    throw std::runtime_error("Unrecognized register!\n");
  }
}

void CPU::writeR8(uint8_t destination, uint8_t value) {
  switch (destination) {
    case REG_B:
      registers.bc.high = value;
  }
}

void CPU::loadR8(uint8_t destination, uint8_t source) {
  uint8_t aSource = readR8(source);
  std::cout << "Value at register: " << static_cast<unsigned>(aSource) << std::endl;
}
