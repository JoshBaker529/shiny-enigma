

#include "../../src/header.hpp"
#include <fstream>
#include <iostream>

int flag_battery(int argc, char *argv[]) {

  std::ifstream inFile;
  Header header;
  bool value;

  inFile.open("../../inputs/flag_battery_on.nes_test");
  if (!inFile) {
    std::cout << "Could not open on file.";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_flag_battery_backed_PRG_ROM();
  if (!value) {
    std::cout << "Function returned false, should have been true.";
    return 1;
  }

  inFile.open("../../inputs/flag_battery_off.nes_test");
  if (!inFile) {
    std::cout << "Could not open on file.";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_flag_battery_backed_PRG_ROM();
  if (value) {
    std::cout << "Function returned true, should have been false.";
    return 2;
  }

  return 0;
}
