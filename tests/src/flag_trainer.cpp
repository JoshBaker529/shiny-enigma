

#include "../../src/header.hpp"
#include <fstream>
#include <iostream>

int flag_trainer(int argc, char *argv[]) {
  std::ifstream inFile;
  Header header;
  bool value;

  inFile.open("../../inputs/flag_trainer_on.nes_test");
  if (!inFile) {
    std::cout << "Could not open on file.";
    return -1;
  }
  header.read(inFile);
  value = header.get_flag_has_trainer();
  if (!value) {
    std::cout << "Function returned false, should have been true";
    return 1;
  }

  inFile.open("../../inputs/flag_trainer_off.nes_test");
  if (!inFile) {
    std::cout << "Could not open off file.";
    return -1;
  }
  header.read(inFile);
  value = header.get_flag_has_trainer();
  if (!value) {
    std::cout << "Function returned true, should have been false";
    return 1;
  }

  return 0;
}
