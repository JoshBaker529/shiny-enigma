

#include "../../src/header.hpp"
#include <fstream>
#include <iostream>

int flag_console_type(int argc, char *argv[]) {
  std::ifstream inFile;
  Header header;
  ConsoleType value;

  // Zero
  inFile.open("../../inputs/flag_VS_Unisystem_off.nes_test");
  if (!inFile) {
    std::cout << "Could not open zero file.";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_flag_console_type();
  if (value != ConsoleType::NES) {
    std::cout << "Function returned " << value << " should have returned "
              << ConsoleType::NES << "\n";
    return 1;
  }

  // One
  inFile.open("../../inputs/flag_VS_Unisystem_on.nes_test");
  if (!inFile) {
    std::cout << "Could not open one file.";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_flag_console_type();
  if (value != ConsoleType::VS_SYSTEM) {
    std::cout << "Function returned " << value << " should have returned "
              << ConsoleType::VS_SYSTEM << "\n";
    return 1;
  }

  // Two
  inFile.open("../../inputs/flag_Playchoice_10_on.nes_test");
  if (!inFile) {
    std::cout << "Could not open two file.";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_flag_console_type();
  if (value != ConsoleType::PLAYCHOICE_10) {
    std::cout << "Function returned " << value << " should have returned "
              << ConsoleType::PLAYCHOICE_10 << "\n";
    return 1;
  }

  // Three
  inFile.open("../../inputs/flag_console_type_extended.nes_test");
  if (!inFile) {
    std::cout << "Could not open three file.";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_flag_console_type();
  if (value != ConsoleType::EXTENDED) {
    std::cout << "Function returned " << value << " should have returned "
              << ConsoleType::EXTENDED << "\n";
    return 1;
  }

  return 0;
}
