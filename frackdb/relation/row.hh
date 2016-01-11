//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

#include <map>
#include <string>
#include <vector>
#include "mpl_type_defs.hh"

class Row {
public:

  Row() = default;
  Row(std::vector<attribute_variant> values, std::map<std::string, int> index_map);

  const attribute_variant& get_variant(std::string attribute_name) const;
  int get_int(std::string attribute_name) const;
  std::string get_var_char(std::string attribute_name) const;

private:

  std::vector<attribute_variant> values;
  std::map<std::string, int> index_map;
};
