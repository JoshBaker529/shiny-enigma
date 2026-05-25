

#include "../../src/header.hpp"
#include <fstream>
#include <iostream>

int flag_VS_Unisystem(int argc, char *argv[]) {
  std::ifstream inFile;
  Header header;
  bool value;

  inFile.open("../../inputs/flag_VS_Unisystem_on.nes_test");
  if (!inFile) {
    std::cout << "Could not open on file.";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_flag_VS_Unisystem();
  if (!value) {
    std::cout << "Function returned false, should have been true.";
    return 1;
  }

  inFile.open("../../inputs/flag_VS_Unisystem_off.nes_test");
  if (!inFile) {
    std::cout << "Could not open on file.";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_flag_VS_Unisystem();
  if (value) {
    std::cout << "Function returned true, should have been false.";
    return 1;
  }

  return 0;
}
