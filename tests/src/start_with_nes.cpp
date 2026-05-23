

#include "../../src/header.hpp"
#include <fstream>
#include <iostream>

int start_with_nes(int argc, char *argv[]) {
  std::ifstream inFile;
  Header header;

  // Test for a correct format
  inFile.open("../../inputs/has_nes.nes_test");
  header.read(inFile);
  inFile.close();

  if (!header.check_nes()) {
    std::cout << "check_nes returned false, should have been true";
    return 1;
  }

  // Test for incorrect format
  inFile.open("../../inputs/missing_nes.nes_test");
  header.read(inFile);
  inFile.close();

  if (header.check_nes()) {
    std::cout << "check_nes returned true, should have been false";
    return 2;
  }

  return 0;
}
