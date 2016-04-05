cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

project(frackdb)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

option(FRACKDB_COVERAGE "Enable test coverage analysis" OFF)
option(FRACKDB_TEST "Enable testing" OFF)
option(FRACKDB_TEST_UNIT "Enable unit testing (only if testing is enabled)" ON)
option(FRACKDB_TEST_INTEGRATION "Enable integration testing (only if testing is enabled)" ON)
option(FRACKDB_COVERAGE "Enable test coverage analysis (debug, linux builds only)" OFF)

set(CMAKE_CXX_FLAGS "-std=c++14 ${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

include_directories(.)
include_directories(frackdb)
add_subdirectory(frackdb)

IF (${FRACKDB_TEST} AND NOT WINDOWS AND NOT APPLE)
  enable_testing()
  add_subdirectory(test EXCLUDE_FROM_ALL)
  add_custom_target(build-tests)
  if (${FRACKDB_TEST_UNIT})
    add_test(NAME unit COMMAND $<TARGET_FILE:frackdb_test_unit>)
    add_dependencies(build-tests frackdb_test_unit)
  endif()

  if (${FRACKDB_TEST_INTEGRATION})
    add_test(NAME integration COMMAND $<TARGET_FILE:frackdb_test_integration>)
    add_dependencies(build-tests frackdb_test_integration)
  endif()

endif()
