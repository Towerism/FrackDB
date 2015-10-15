INCLUDE(biicode/boost/setup)
INCLUDE(Towerism/CMake/add_cxx_flags)
INCLUDE(Towerism/CMake/code_coverage)

OPTION(FRACKDB_COVERAGE "Enable test coverage analysis of FrackDB" OFF)

FIND_PACKAGE(Boost 1.58.0)
IF (NOT ${Boost_FOUND})
  BII_FIND_BOOST()
ENDIF()

ADD_BII_TARGETS()

ADD_CXX_FLAGS("-std=c++14")

IF (${FRACKDB_COVERAGE} AND NOT WINDOWS AND NOT APPLE)
  ADD_CXX_FLAGS("--coverage")
  SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
  SETUP_TARGET_FOR_COVERAGE(
    coverage
    ${BII_test_unit_TARGET}
    coverage
  )
ENDIF()