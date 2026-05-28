

#include "../../src/header.hpp"
#include <fstream>
#include <iostream>

int flag_TV_system_9(int argc, char *argv[]) {
  std::ifstream inFile;
  Header header;
  TVSystem value;

  inFile.open("../../inputs/flag_TV_system_9_NTSC.nes_test");
  if (!inFile) {
    std::cout << "Could not open NTSC file\n";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_TV_system_9();
  if (value != TVSystem::NTSC) {
    std::cout << "Function returned " << value << ", should have returned "
              << TVSystem::NTSC;
    return 1;
  }

  inFile.open("../../inputs/flag_TV_system_9_PAL.nes_test");
  if (!inFile) {
    std::cout << "Could not open PAL file\n";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_TV_system_9();
  if (value != TVSystem::PAL) {
    std::cout << "Function returned " << value << ", should have returned "
              << TVSystem::PAL;
    return 1;
  }

  return 0;
}
