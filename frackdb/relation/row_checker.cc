#include "row_checker.hh"

Row_checker::Row_checker(const std::vector<std::shared_ptr<Attribute>>& attributes,
                         const std::vector<std::string>& row) : attributes(attributes), row(row) {
}

void Row_checker::check() const {
  check_size();
  check_types();
}

void Row_checker::check_size() const {
  if (row.size() != attributes.size())
    throw Row_size_exception();
}

void Row_checker::check_types() const {
  if (!types_are_matching())
    throw Type_match_exception();
}

bool Row_checker::types_are_matching() const {
  bool types_match = true;
  for (int i = 0; i < row.size(); ++i)
    types_match &= attributes[i]->is_type_compatible_with(row[i]);
  return types_match;
}
