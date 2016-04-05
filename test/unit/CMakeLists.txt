set(UNIT_SRCS
  test_attribute.cc 
  test_attribute_list.cc
  test_comparison.cc
  test_condition.cc
  test_query.cc
  test_relation.cc
  )
add_library(unit OBJECT ${UNIT_SRCS})
