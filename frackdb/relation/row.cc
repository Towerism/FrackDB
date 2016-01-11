//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "mpl_type_defs.hh"
#include "row.hh"

Row::Row(std::vector<attribute_variant> values, std::map<std::string, int> index_map) : values(values), index_map(index_map) {
}

const attribute_variant& Row::get_variant(std::string attribute_name) const {
  int index = index_map.at(attribute_name);
  return values[index];
}

int Row::get_int(std::string attribute_name) const {
  int index = index_map.at(attribute_name);
  return boost::get<int>(values[index]);
}

std::string Row::get_var_char(std::string attribute_name) const {
  int index = index_map.at(attribute_name);
  return boost::get<std::string>(values[index]);
}
