

#include "../../src/header.hpp"
#include <fstream>
#include <iostream>

int flag_timing_mode(int argc, char *argv[]) {

  std::ifstream inFile;
  Header header;
  TimingMode value;

  inFile.open("../../inputs/timing_ntsc.nes_test");
  if (!inFile) {
    std::cout << "Could not open NTSC file\n";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_timing_mode();
  if (value != TimingMode::NTSC_NES) {
    std::cout << "Function returned " << value << ", should have returned "
              << TimingMode::NTSC_NES;
    return 1;
  }

  inFile.open("../../inputs/timing_pal.nes_test");
  if (!inFile) {
    std::cout << "Could not open PAL file\n";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_timing_mode();
  if (value != TimingMode::PAL_NES) {
    std::cout << "Function returned " << value << ", should have returned "
              << TimingMode::PAL_NES;
    return 1;
  }

  inFile.open("../../inputs/timing_multi.nes_test");
  if (!inFile) {
    std::cout << "Could not open MULTI file\n";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_timing_mode();
  if (value != TimingMode::MULTIREGION) {
    std::cout << "Function returned " << value << ", should have returned "
              << TimingMode::MULTIREGION;
    return 1;
  }

  inFile.open("../../inputs/timing_dendy.nes_test");
  if (!inFile) {
    std::cout << "Could not open DENDY file\n";
    return -1;
  }
  header.read(inFile);
  inFile.close();
  value = header.get_timing_mode();
  if (value != TimingMode::DENDY) {
    std::cout << "Function returned " << value << ", should have returned "
              << TimingMode::DENDY;
    return 1;
  }

  return 0;
}
