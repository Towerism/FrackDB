//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

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
