
#include "../../src/header.hpp"
#include <fstream>
#include <iostream>

int flag_nametable_mirroring(int argc, char *argv[]) {
  std::ifstream inFile;
  Header header;
  NametableMirroring value;

  inFile.open("../../inputs/flag_nametable_mirroring_horizontal.nes_test");
  if (!inFile) {
    std::cout << "Could not open horizontal file.";
    return -1;
  }
  header.read(inFile);
  inFile.close();

  value = header.get_flag_nametable_mirroring();
  if (value != NametableMirroring::HORIZONTAL) {
    std::cout << "Function returned vertical, should have been horizontal";
    return 1;
  }

  inFile.open("../../inputs/flag_nametable_mirroring_vertical.nes_test");
  if (!inFile) {
    std::cout << "Could not open vertical file.";
    return -1;
  }
  header.read(inFile);
  inFile.close();

  value = header.get_flag_nametable_mirroring();
  if (value != NametableMirroring::VERTICAL) {
    std::cout << "Function returned horizontal, should have been vertical";
    return 1;
  }

  return 0;
}
