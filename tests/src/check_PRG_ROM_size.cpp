
#include "../../src/header.hpp"
#include <fstream>
#include <iostream>

static const int kilobyte = 1024;
static constexpr int byte_conversion = kilobyte * 16;

int check_PRG_ROM_size(int argc, char *argv[]) {

  std::ifstream inFile;
  Header header;
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

  return 0;
}
