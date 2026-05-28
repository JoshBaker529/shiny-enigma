cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
project(shiny-enigma-TESTS)


set(header_test_files 
  start_with_nes.cpp
  check_PRG_ROM_size.cpp
  check_CHR_ROM_size.cpp
  flag_nametable_mirroring.cpp
  flag_battery.cpp
  flag_trainer.cpp
  flag_alt_nametable_layout.cpp
  flag_VS_Unisystem.cpp
  flag_Playchoice_10.cpp
  flag_console_type.cpp
  flag_is_20_format.cpp
  check_PRG_RAM_size.cpp
  flag_TV_system_9.cpp
  flag_TV_system_10.cpp
)

enable_testing()

create_test_sourcelist (
  Header_Tests
  Header_driver.cpp
  ${header_test_files}
)

add_executable(Header_driver ${Header_Tests} ../../src/header.cpp)

foreach (test ${header_test_files})
  get_filename_component (TName ${test} NAME_WE)

  add_test (NAME ${TName} COMMAND Header_driver ${TName})
endforeach ()
