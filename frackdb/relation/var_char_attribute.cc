//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "var_char_attribute.hh"

Var_char_attribute::Var_char_attribute(std::string name, int char_limit) : char_limit(char_limit) {
  this->name = name;
}

bool Var_char_attribute::is_type_compatible_with(const std::string& str) const {
  return str.size() <= char_limit;
}

attribute_variant Var_char_attribute::make_value(std::string str) const {
  return attribute_variant(str);
}
