//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "names_extractor.hh"

std::vector<std::string> Names_extractor::extract(const std::vector<std::shared_ptr<Attribute>>& attribute_vec) {
  std::vector<std::string> names;
  for (auto attribute : attribute_vec)
    names.push_back(attribute->get_name());
  return names;
}
