cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
project(shiny-enigma-TESTS)


set(header_test_files 
  start_with_nes.cpp
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
