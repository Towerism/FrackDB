#include <algorithm>
#include "attribute_list.hh"
#include "row_checker.hh"

Attribute_list::Attribute_list(std::vector<Attribute*> attributes) {
  init_attribute_ptrs(attributes);
  init_names();
}

void Attribute_list::init_attribute_ptrs(std::vector<Attribute*> attributes) {
  for (auto attribute : attributes)
    this->attributes.emplace_back(attribute);
}

void Attribute_list::init_names() {
  for (auto attribute : attributes)
    names.push_back(attribute->get_name());
}

void Attribute_list::safe_set_primary_key(std::vector<std::string> pkey) {
  check_primary_key(pkey);
  primary_key = pkey;
}

void Attribute_list::check_primary_key(std::vector<std::string>& pkey) {
  primary_key_starting_iterator = std::search(names.begin(), names.end(), pkey.begin(), pkey.end());
  if (primary_key_starting_iterator == names.end())
    throw Primary_key_exception();
}

void Attribute_list::check_row(const std::vector<std::string>& row) const {
  Row_checker row_checker(attributes, row);
  row_checker.check();
}

std::string Attribute_list::concatenate_key_for(std::vector<std::string>& row) const {
  std::vector<std::string> key = calculate_key(row);
  return concatenate_key(key);
}

std::vector<std::string> Attribute_list::calculate_key(const std::vector<std::string>& row) const {
  int primary_key_starting_index = primary_key_starting_iterator - names.begin();
  auto key_starting_iterator = row.begin() + primary_key_starting_index;
  return std::vector<std::string>(key_starting_iterator, key_starting_iterator + primary_key.size());
}

std::string Attribute_list::concatenate_key(const std::vector<std::string>& key) const {
  return std::accumulate(key.begin(), key.end(), std::string());
}
