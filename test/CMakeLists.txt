include(gtest)

set(LIBS_TO_TEST
  evaluation
  relation
  querying
  )
set(TEST_LIBS
  ${LIBS_TO_TEST}
  gtest
  gtest_main
  )

if (${FRACKDB_TEST_UNIT})
  add_subdirectory(unit)

  add_executable(frackdb_test_unit $<TARGET_OBJECTS:unit>)

  target_link_libraries(frackdb_test_unit ${TEST_LIBS})
endif()

if (${FRACKDB_TEST_INTEGRATION})
  add_subdirectory(integration)

  add_executable(frackdb_test_integration $<TARGET_OBJECTS:integration>)

  target_link_libraries(frackdb_test_integration ${TEST_LIBS})
endif()

if (FRACKDB_COVERAGE AND NOT WIN32 AND NOT APPLE)
  include(code_coverage)
  setup_target_for_coverage(
    coverage
    ctest
    coverage
    "-VV"
  )
endif()
