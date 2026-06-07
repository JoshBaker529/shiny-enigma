
#include "header.hpp"
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <iostream>

static const int kilobyte = 1024;

Header::Header() {}

Header::~Header() {}

const uint8_t &Header::operator[](int index) const { return raw_header[index]; }

void Header::read(std::ifstream &inFile) {
  uint8_t c;
  for (int i = 0; i < size; i++) {
    inFile.read(reinterpret_cast<char *>(&c), 1);
    raw_header[i] = static_cast<uint8_t>(c);
  }
}

bool Header::check_nes() {
  if (raw_header[0] != static_cast<uint8_t>(0x4E) ||
      raw_header[1] != static_cast<uint8_t>(0x45) ||
      raw_header[2] != static_cast<uint8_t>(0x53) ||
      raw_header[3] != static_cast<uint8_t>(0x1A))
    return false;

  return true;
}

int Header::get_PRG_ROM_size() {
  int value = 0;

  // MSB
  int msb = raw_header[9] & 0xF;

  // Is it in exponent-multiplier format?
  if (msb == 0xF) {

    /*
      Multiplier formatting:

      EEEE EEMM
      |||| ||++---- Multipler: MM * 2 + 1
      ++++-++------ Exponent:  2 ^ EEEEEE

      Final calculation:
      [ 2 ^ EEEEEE ] * [ MM * 2 + 1 ]


    */

    int lsb = raw_header[4];
    int multiplier = lsb & 3;
    int exponent = (lsb & ~3) >> 2;

    value = std::pow(2, exponent);
    value *= (multiplier * 2 + 1);

    return value;
  }

  // Not exponent-multiplier format
  value |= (msb << 8);
  // LSB
  value |= raw_header[4];

  // value now holds the 12-bit size
  int size = (16 * kilobyte);
  return (value * size);
}

int Header::get_CHR_ROM_size() {

  int value = 0;

  // MSB
  int msb = raw_header[9] >> 4;

  // Is it in exponent-multiplier format?
  if (msb == 0xF) {

    /*
      Multiplier formatting:

      EEEE EEMM
      |||| ||++---- Multipler: MM * 2 + 1
      ++++-++------ Exponent:  2 ^ EEEEEE

      Final calculation:
      [ 2 ^ EEEEEE ] * [ MM * 2 + 1 ]


    */

    int lsb = raw_header[5];
    int multiplier = lsb & 3;
    int exponent = (lsb & ~3) >> 2;

    value = std::pow(2, exponent);
    value *= (multiplier * 2 + 1);

    return value;
  }

  // Not exponent-multiplier format
  value |= (msb << 8);
  // LSB
  value |= raw_header[5];

  // value now holds the 12-bit size
  int size = (8 * kilobyte);
  return (value * size);
}

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

ConsoleType Header::get_flag_console_type() {
  // First two bits
  return static_cast<ConsoleType>(raw_header[7] & 3);
}

bool Header::is_20_format() {
  if ((raw_header[7] & 0x0C) == 0x08)
    return true;
  return false;
}

// NES 2.0 formatting

int Header::get_PRG_RAM_size() {
  int value;
  if (is_20_format()) {
    value = raw_header[10] & 0xF;
    if (value == 0)
      return 0;
    return 64 << value;
  }

  value = raw_header[8];
  if (value == 0) {
    return 8 * kilobyte;
  }
  return value * (8 * kilobyte);
}

//////////////////////////////////////////////////////////////////////////////
// NES 2.0 formatting
//////////////////////////////////////////////////////////////////////////////

int Header::get_PRG_NVRAM_size() {
  int value;
  if (!is_20_format()) {
    return -1;
  }

  value = raw_header[10] & 0xF0;
  value >>= 4;

  if (value == 0) {
    return 0;
  }

  return (64 << value);
}

int Header::get_CHR_RAM_size() {
  int value;
  value = raw_header[11] & 0xF;
  if (value == 0)
    return 0;
  return 64 << value;
}

int Header::get_CHR_NVRAM_size() {
  int value;
  value = raw_header[11] & 0xF0;
  if (value == 0)
    return 0;
  value >>= 4;
  return 64 << value;
}

//////////////////////////////////////////////////////////////////////////////
// iNES formatting
//////////////////////////////////////////////////////////////////////////////

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

bool Header::get_flag_has_PRG_RAM() {
  if (is_20_format()) {
    return (raw_header[10] & 0xF) > 0;
  }
  return (raw_header[10] >> 4) & 1;
}

bool Header::get_flag_bus_conflicts() { return (raw_header[10] >> 5) & 1; }
