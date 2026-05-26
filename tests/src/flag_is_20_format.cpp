

#include "../../src/header.hpp"
#include <fstream>
#include <iostream>

int flag_is_20_format(int argc, char *argv[]) {
  std::ifstream inFile;
  Header header;
  bool value;

  inFile.open("../../inputs/flag_20_format_on.nes_test");
  if (!inFile) {
    std::cout << "Could not open on file.";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.is_20_format();
  if (!value) {
    std::cout << "Function returned false, should have been true.";
    return 1;
  }

  inFile.open("../../inputs/flag_20_format_off.nes_test");
  if (!inFile) {
    std::cout << "Could not open off file.";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.is_20_format();
  if (value) {
    std::cout << "Function returned true, should have been false.";
    return 1;
  }

  return 0;
}
