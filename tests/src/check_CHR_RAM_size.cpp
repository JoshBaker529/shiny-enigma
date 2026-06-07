

#include "../../src/header.hpp"
#include <fstream>
#include <iostream>

int check_CHR_RAM_size(int argc, char *argv[]) {

  std::ifstream inFile;
  Header header;
  int value;

  inFile.open("../../inputs/chr_ram_size_0.nes_test");
  if (!inFile) {
    std::cout << "Could not open 0 file.";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_CHR_RAM_size();
  if (value != 0) {
    std::cout << "Function returned " << value << ", should have returned 0";
    return 1;
  }

  inFile.open("../../inputs/chr_ram_size_F.nes_test");
  if (!inFile) {
    std::cout << "Could not open F file.";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_CHR_RAM_size();
  int correct = 64 << 0xF;
  if (value != correct) {
    std::cout << "Function returned " << value << ", should have returned "
              << correct;
    return 1;
  }

  return 0;
}
