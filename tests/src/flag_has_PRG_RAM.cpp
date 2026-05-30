

#include "../../src/header.hpp"
#include <fstream>
#include <iostream>

int flag_has_PRG_RAM(int argc, char *argv[]) {

  std::ifstream inFile;
  Header header;
  bool value;

  inFile.open("../../inputs/flag_PRG_RAM_20_on.nes_test");
  if (!inFile) {
    std::cout << "Could not open 2.0 on file.";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_flag_has_PRG_RAM();
  if (!value) {
    std::cout << "2.0 on Function returned false, should have been true.";
    return 1;
  }

  inFile.open("../../inputs/flag_PRG_RAM_iNES_on.nes_test");
  if (!inFile) {
    std::cout << "Could not open iNES on file.";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_flag_has_PRG_RAM();
  if (!value) {
    std::cout << "iNES on Function returned false, should have been true.";
    return 2;
  }

  inFile.open("../../inputs/flag_PRG_RAM_off.nes_test");
  if (!inFile) {
    std::cout << "Could not open off file.";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_flag_has_PRG_RAM();
  if (value) {
    std::cout << "Function returned true, should have been false.";
    return 2;
  }

  return 0;
}
