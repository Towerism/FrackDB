OPTION(FRACKDB_COVERAGE "Enable test coverage analysis of FrackDB" OFF)

ADD_BII_TARGETS()

MACRO(ADD_CXX_FLAGS CXX_FLAGS)
  SET(CMAKE_CXX_FLAGS_${CMAKE_BUILD_TYPE} "${CMAKE_CXX_FLAGS_${CMAKE_BUILD_TYPE}} ${CXX_FLAGS}")
ENDMACRO()

# enable c++14
ADD_CXX_FLAGS("-std=c++14")

IF (${FRACKDB_COVERAGE} AND NOT WINDOWS AND NOT APPLE)
  ADD_CXX_FLAGS("-O0 -fprofile-arcs -ftest-coverage")
  LIST(APPEND CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage -lgcov")
  INCLUDE(Towerism/Coverage/code_coverage)
  SETUP_TARGET_FOR_COVERAGE(
    coverage
    ${BII_test_unit_TARGET}
    coverage
  )
ENDIF()