
#include "../../src/header.hpp"
#include <fstream>
#include <iostream>

static const int kilobyte = 1024;
static constexpr int byte_conversion = kilobyte * 16;

int check_PRG_ROM_size(int argc, char *argv[]) {

  std::ifstream inFile;
  Header header;

  // Size of 0
  inFile.open("../../inputs/prg_size_0.nes_test");
  if (!inFile) {
    std::cout << "Could not open file\n";
    return -1;
  }
  header.read(inFile);
  inFile.close();

  int size = header.get_PRG_ROM_size();
  if (size != 0) {
    std::cout << "Size was non-zero given a size of 0\n";
    return 1;
  }

  // Size of 0FF
  inFile.open("../../inputs/prg_size_255.nes_test");
  if (!inFile) {
    std::cout << "Could not open file\n";
    return -1;
  }
  header.read(inFile);
  inFile.close();

  size = header.get_PRG_ROM_size();
  if (size != (0xFF * byte_conversion)) {
    std::cout << "Incorrect size: " << size << " should be "
              << (0xFF * byte_conversion) << "\n";
    return 2;
  }

  // Size of EFF
  inFile.open("../../inputs/prg_size_EFF.nes_test");
  header.read(inFile);
  inFile.close();
  size = header.get_PRG_ROM_size();
  if (size != (0xEFF * byte_conversion)) {
    std::cout << "Incorrect size for 0xEFF: " << size << " should be "
              << (0xEFF * byte_conversion) << "\n";
    return 3;
  }

  // Size of exponent-multiplier formatting
  inFile.open("../../inputs/prg_size_exp_mul_format.nes_test");
  header.read(inFile);
  inFile.close();
  size = header.get_PRG_ROM_size();

  // This file has the LSB as 0x72 and the exponent nibble of F
  // Should have 2 ^ 28 * 5 bytes, or 1,342,177,280 bytes
  // I just picked numbers, there is no significance to them
  if (size != 1'342'177'280) {
    std::cout << "Incorrect size: " << size << " should be " << 1'342'177'280
              << "\n";
    return 4;
  }

  return 0;
}
