set(RELATION_SRCS
  attribute_list.cc
  index_mapper.cc
  integer_attribute.cc
  names_extractor.cc
  primary_key_checker.cc
  relation.cc
  row.cc
  row_checker.cc
  var_char_attribute.cc
  )
add_library(relation ${RELATION_SRCS})
