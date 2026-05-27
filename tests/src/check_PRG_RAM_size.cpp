

#include "../../src/header.hpp"
#include <fstream>
#include <iostream>
static const int kilobyte = 1024;

int check_PRG_RAM_size(int argc, char *argv[]) {
  std::ifstream inFile;
  Header header;
  int value;

  // Testing the NES 2.0 format
  inFile.open("../../inputs/prg_ram_20_size_0.nes_test");
  if (!inFile) {
    std::cout << "Could not open 2.0 0 file.\n";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_PRG_RAM_size();
  if (value != 0) {
    std::cout << "One: Function returned " << value
              << ", should have returned 0";
    return 1;
  }

  inFile.open("../../inputs/prg_ram_20_size_F.nes_test");
  if (!inFile) {
    std::cout << "Could not open 2.0 F file.\n";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_PRG_RAM_size();
  int correct = 64 << 0xF;
  if (value != correct) {
    std::cout << "Two: Function returned " << value << ", should have returned "
              << correct;
    return 1;
  }

  // Testing the iNES format
  int size = 8 * kilobyte;
  inFile.open("../../inputs/prg_ram_orig_size_0.nes_test");
  if (!inFile) {
    std::cout << "Could not open iNES 0 file.\n";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_PRG_RAM_size();
  correct = 8 * kilobyte;
  if (value != correct) {
    std::cout << "Three: Function returned " << value
              << ", should have returned " << correct;
    return 1;
  }

  inFile.open("../../inputs/prg_ram_orig_size_FF.nes_test");
  if (!inFile) {
    std::cout << "Could not open iNES F file.\n";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_PRG_RAM_size();
  correct = 0xFF * (8 * kilobyte);
  if (value != correct) {
    std::cout << "Four: Function returned " << value
              << ", should have returned " << correct;
    return 1;
  }

  return 0;
}
