

#include "../../src/header.hpp"
#include <fstream>
#include <iostream>

int flag_TV_system_10(int argc, char *argv[]) {
  std::ifstream inFile;
  Header header;
  TVSystem value;

  inFile.open("../../inputs/flag_TV_system_10_NTSC.nes_test");
  if (!inFile) {
    std::cout << "Could not open NTSC file\n";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_TV_system_10();
  if (value != TVSystem::NTSC) {
    std::cout << "Function returned " << value << ", should have returned "
              << TVSystem::NTSC;
    return 1;
  }

  inFile.open("../../inputs/flag_TV_system_10_PAL.nes_test");
  if (!inFile) {
    std::cout << "Could not open NTSC file\n";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_TV_system_10();
  if (value != TVSystem::PAL) {
    std::cout << "Function returned " << value << ", should have returned "
              << TVSystem::PAL;
    return 1;
  }

  inFile.open("../../inputs/flag_TV_system_10_DUAL_1.nes_test");
  if (!inFile) {
    std::cout << "Could not open DUAL 1 file\n";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_TV_system_10();
  if (value != TVSystem::DUAL) {
    std::cout << "Function returned " << value << ", should have returned "
              << TVSystem::DUAL;
    return 1;
  }

  inFile.open("../../inputs/flag_TV_system_10_DUAL_3.nes_test");
  if (!inFile) {
    std::cout << "Could not open DUAL 3 file\n";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_TV_system_10();
  if (value != TVSystem::DUAL) {
    std::cout << "Function returned " << value << ", should have returned "
              << TVSystem::DUAL;
    return 1;
  }

  return 0;
}
