
#include "../../src/header.hpp"
#include <fstream>
#include <iostream>

int flag_VS_PPU_type(int argc, char *argv[]) {

  std::ifstream inFile;
  Header header;

  // Size of 0
  inFile.open("../../inputs/flag_VS_PPU_type_0.nes_test");
  if (!inFile) {
    std::cout << "Could not open 0 file\n";
    return -1;
  }
  header.read(inFile);
  inFile.close();

  int type = header.get_VS_PPU_type();
  if (type != 0) {
    std::cout << "Size was non-zero given a size of 0\n";
    return 1;
  }

  // Size of F
  inFile.open("../../inputs/flag_VS_PPU_type_F.nes_test");
  if (!inFile) {
    std::cout << "Could not open 0 file\n";
    return -1;
  }
  header.read(inFile);
  inFile.close();

  type = header.get_VS_PPU_type();
  if (type != 0xF) {
    std::cout << "Size was non-zero given a size of 0\n";
    return 1;
  }
  return 0;
}
