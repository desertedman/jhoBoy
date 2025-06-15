#include <cstdint>
#include <iostream>
#include <array>
#include <numeric>

int main() {
  std::array<uint8_t, 0xFFFF> memoryMap;
  memoryMap.fill(1);
  auto bignum = std::accumulate(memoryMap.begin(), memoryMap.end(), 1);

  std::cout << "Sum is: " << bignum << std::endl;

  return 0;
}
