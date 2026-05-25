

#ifndef HEADER_HPP
#define HEADER_HPP

#include <array>
#include <cstdint>
#include <fstream>

// The different nametable mirroring modes
enum NametableMirroring { VERTICAL, HORIZONTAL };

// Different types of consoles the game was made for
enum ConsoleType { NES, VS_SYSTEM, PLAYCHOICE_10, EXTENDED };

// TV System flags used in bytes 9 and 10 of the header
enum TVSystem { NTSC, PAL, DUAL };

// Holds all the information from
class Header {
public:
  // Constructors
  Header();
  Header(Header &&) = default;
  Header(const Header &) = default;
  Header &operator=(Header &&) = default;
  Header &operator=(const Header &) = default;
  ~Header();

  // Operator overloads

  const uint8_t &operator[](int index) const;

  // Functions

  // Reads the first 16 bytes from the rom file
  void read(std::ifstream &inFile);

  // Ensures the file is actually an NES file
  // First 4 bytes should be:
  // 'N' 'E' 'S' <EOF>
  bool check_nes();

  // Returns the size of the PRG ROM section in bytes
  int get_PRG_ROM_size();

  // Returns the size of the CHR ROM section in bytes
  // 0 means board uses CHR RAM
  int get_CHR_ROM_size();

  // Returns the type of the nametable mirroring
  // Either VERTICAL or HORIZONTAL
  NametableMirroring get_flag_nametable_mirroring();

  // Returns whether the cartridge contains battery backed
  // PRG RAM or other persistent memory
  bool get_flag_battery_backed_PRG_ROM();

  // Returns whether the ROM has a trainer section
  bool get_flag_has_trainer();

  // Returns whether there is an alternative
  // nametable layout
  bool get_flag_alt_nametable_layout();

  // ?? Not sure what this flag is for
  bool get_flag_VS_Unisystem();

  // Returns whether there is 8KB of Hint Screen Data
  // after the CHR data
  // Not really used with the NES PPU
  bool get_flag_Playchoice_10();

  // Returns the console type
  ConsoleType get_flag_console_type();

  // Returns whether the header format is NES 2.0
  bool is_20_format();

  // NES 2.0 formatting

  // Returns the size of the PRG RAM
  int get_PRG_RAM_size();

  // Returns the TV system flag from byte 9
  // Either NTSC or PAL
  TVSystem get_TV_system_9();

  // Returns the TV system flag from byte 10
  // Either NTSC, PAL, or DUAL
  TVSystem get_TV_system_10();

  // Returns whether PRG RAM is present
  bool get_flag_has_PRG_RAM();

  // Returns whether there are bus conflicts
  bool get_flag_bus_conflicts();

private:
  // The raw data held in the header
  std::array<uint8_t, 16> raw_header;

  // The size of the header in bytes
  static const int size = 16;
};

#endif // !HEADER_HPP
