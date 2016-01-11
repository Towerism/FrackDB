//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

#include <string>
#include <vector>

class Index_mapper {
public:

  Index_mapper(std::vector<std::string> from_vector, std::vector<std::string> to_vector);

  int get(int i) const;

private:

  std::vector<int> mapping;
  std::vector<std::string> from_vector;
  std::vector<std::string> to_vector;

  void init_mapping();
  void map_next_index_to(int index);
  void map_index(int from, int to);
};
