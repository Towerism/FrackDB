OPTION(FRACKDB_COVERAGE "Enable test coverage analysis of FrackDB" OFF)

FIND_PACKAGE(Boost 1.58.0)
IF (NOT ${Boost_FOUND})
  INCLUDE(biicode/boost/setup)
  SET(BII_BOOST_GLOBAL_OVERRIDE_VERSION 1.58.0)
  BII_FIND_BOOST()
ENDIF()

ADD_BII_TARGETS()

INCLUDE(Towerism/CMake/add_cxx_flags)
ADD_CXX_FLAGS("-std=c++14")

IF (${FRACKDB_COVERAGE} AND NOT WINDOWS AND NOT APPLE)
  ADD_CXX_FLAGS("--coverage")
  SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
  INCLUDE(Towerism/CMake/code_coverage)
  SETUP_TARGET_FOR_COVERAGE(
    coverage
    ${BII_test_unit_TARGET}
    coverage
  )
ENDIF()