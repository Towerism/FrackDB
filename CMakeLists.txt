ADD_BII_TARGETS()
OPTION(FRACKDB_COVERAGE "Enable test coverage analysis of FrackDB" OFF)
MESSAGE("Source dir is ${CMAKE_SOURCE_DIR}")
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../../cmake")

IF (FRACKDB_COVERAGE AND NOT WINDOWS AND NOT APPLE)
  SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
  SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage -lgcov")
  include(code_coverage)
  setup_target_for_coverage(
    coverage
    Towerism_FrackDB_test_unit
    coverage
  )
ENDIF()

# enable c++14
SET(CMAKE_CXX_FLAGS "-std=c++14 ${CMAKE_CXX_FLAGS}")