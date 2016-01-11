//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "index_mapper.hh"

Index_mapper::Index_mapper(std::vector<std::string> from_vector, std::vector<std::string> to_vector)
  : from_vector(from_vector), to_vector(to_vector) {
  init_mapping();
}

int Index_mapper::get(int i) const {
  return mapping[i];
}

void Index_mapper::init_mapping() {
  for (int i = 0; i < to_vector.size(); ++i)
    map_next_index_to(i);
}

void Index_mapper::map_next_index_to(int index) {
  for (int index_found_at = index; index_found_at < from_vector.size(); ++index_found_at)
    map_index(index_found_at, index);
}

void Index_mapper::map_index(int from, int to) {
  if (from_vector[from] == to_vector[to])
    mapping.push_back(from);
}
