
#include "header.hpp"
#include <cstddef>
#include <cstdint>

static const int kilobyte = 1024;

Header::Header() {}

Header::~Header() {}

const uint8_t &Header::operator[](int index) const { return raw_header[index]; }

void Header::read(std::ifstream &inFile) {
  char c;
  for (int i = 0; i < size; i++) {
    inFile.get(c);
    raw_header[i] = c;
  }
}

bool Header::check_nes() {
  if (raw_header[0] != static_cast<uint8_t>('N') ||
      raw_header[1] != static_cast<uint8_t>('E') ||
      raw_header[2] != static_cast<uint8_t>('S') ||
      raw_header[3] != static_cast<uint8_t>(0x1A))
    return false;

  return true;
}

int Header::get_PRG_ROM_size() { return raw_header[4] * (16 * kilobyte); }

int Header::get_CHR_ROM_size() { return raw_header[5] * (8 * kilobyte); }

NametableMirroring Header::get_flag_nametable_mirroring() {
  return static_cast<NametableMirroring>(raw_header[6] & 1);
}

bool Header::get_flag_battery_backed_PRG_ROM() {
  return (raw_header[6] >> 1) & 1;
}

bool Header::get_flag_has_trainer() { return (raw_header[6] >> 2) & 1; }

bool Header::get_flag_alt_nametable_layout() {
  return (raw_header[6] >> 3) & 1;
}

bool Header::get_flag_VS_Unisystem() { return (raw_header[7] & 1); }

bool Header::get_flag_Playchoice_10() { return (raw_header[7] >> 1) & 1; }

bool Header::is_20_format() {
  if ((raw_header[7] & 0x0C) == 0x08)
    return true;
  return false;
}

// NES 2.0 formatting

int Header::get_PRG_RAM_size() {
  if (raw_header[8] == 0)
    return 8 * kilobyte;
  return raw_header[8] * (8 * kilobyte);
}

TVSystem Header::get_TV_system_9() {
  return static_cast<TVSystem>(raw_header[9] & 1);
}

TVSystem Header::get_TV_system_10() {
  // This flag had to be special, didn't it?
  uint8_t value = raw_header[10] & 0b11;
  if (value == 0)
    return TVSystem::NTSC;
  if (value == 2)
    return TVSystem::PAL;
  return TVSystem::DUAL;
}

bool Header::get_flag_has_PRG_RAM() { return (raw_header[10] >> 4) & 1; }

bool Header::get_flag_bus_conflicts() { return (raw_header[10] >> 5) & 1; }
