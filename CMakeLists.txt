OPTION(FRACKDB_COVERAGE "Enable test coverage analysis of FrackDB" OFF)

ADD_BII_TARGETS()

IF (FRACKDB_COVERAGE AND NOT WINDOWS AND NOT APPLE)
  SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
  SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage -lgcov")
  include(Towerism/Coverage/code_coverage)
  setup_target_for_coverage(
    coverage
    ${BII_test_unit_TARGET}
    coverage
  )
ENDIF()

# enable c++14
SET(CMAKE_CXX_FLAGS "-std=c++14 ${CMAKE_CXX_FLAGS}")