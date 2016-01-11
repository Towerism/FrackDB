//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include <algorithm>
#include "attribute_list.hh"
#include "names_extractor.hh"
#include "primary_key_checker.hh"
#include "row_checker.hh"

Attribute_list::Attribute_list(std::vector<Attribute*> attributes, std::vector<std::string> primary_key)
  : attributes(attributes.begin(), attributes.end()), primary_key(primary_key),
    name_to_key_mapper(Names_extractor::extract(this->attributes), primary_key) {
  check_primary_key();
}

void Attribute_list::check_primary_key() {
  Primary_key_checker primary_key_checker(attributes, primary_key);
  primary_key_checker.check();
}

void Attribute_list::check_row(const std::vector<std::string>& row) const {
  Row_checker row_checker(attributes, row);
  row_checker.check();
}

std::string Attribute_list::concatenate_key_for(const std::vector<std::string>& row) const {
  std::vector<std::string> key = calculate_key(row);
  return concatenate_key(key);
}

std::vector<std::string> Attribute_list::calculate_key(const std::vector<std::string>& row) const {
  std::vector<std::string> key;
  for (int i = 0; i < primary_key.size(); ++i)
    key.push_back(row[name_to_key_mapper.get(i)]);
  return key;
}

std::string Attribute_list::concatenate_key(const std::vector<std::string>& key) const {
  return std::accumulate(key.begin(), key.end(), std::string());
}

std::vector<attribute_variant> Attribute_list::make_variant_list_from_row(const std::vector<std::string>& row) const {
  std::vector<attribute_variant> variant_list;
  for (int i = 0; i < attributes.size(); ++i)
    variant_list.push_back(attributes[i]->make_value(row[i]));
  return variant_list;
}

std::map<std::string, int> Attribute_list::get_index_map() const {
  auto names = Names_extractor::extract(this->attributes);
  std::map<std::string, int> index_map;
  for (int i = 0; i < names.size(); ++i)
    index_map[names[i]] = i;
  return index_map;
}
