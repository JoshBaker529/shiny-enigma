
#include "header.hpp"
#include <fstream>
#include <ios>
#include <iostream>

int main(int argc, char *argv[]) {

  if (argc == 1) {
    std::cout << "Usage:\nshiny-enigma <ROM File>" << std::endl;
  }

  std::ifstream inFile;
  Header header;

  // Hard coded to be the second arg, will change later
  inFile.open(argv[1], std::ios::binary);

  if (!inFile) {
    std::cerr << "Could not open file " << argv[1] << std::endl;
  }

  header.read(inFile);

  if (!header.check_nes()) {
    std::cerr << "File given is not a valid NES ROM file." << std::endl;
  }

  return 0;
}
