#include <algorithm>
#include "attribute_list.hh"

Attribute_list::Attribute_list(std::vector<std::string> names) : names(names) {
}

void Attribute_list::safe_set_primary_key(std::vector<std::string> primary_key) {
  check_primary_key(primary_key);
  this->primary_key = primary_key;
}

void Attribute_list::check_primary_key(std::vector<std::string>& primary_key) {
  primary_key_starting_iterator = std::search(names.begin(), names.end(),
                                     primary_key.begin(), primary_key.end());
  if (primary_key_starting_iterator == names.end())
    throw Primary_key_exception();
}

std::string Attribute_list::concatenate_key_for(const std::vector<std::string>& row) const {
  std::vector<std::string> key = calculate_key(row);
  return concatenate_key(key);
}

std::string Attribute_list::concatenate_key(const std::vector<std::string>& key) const {
  return std::accumulate(key.begin(), key.end(), std::string());
}

std::vector<std::string> Attribute_list::calculate_key(const std::vector<std::string>& row) const {
  int primary_key_starting_index = primary_key_starting_iterator - names.begin();
  auto key_starting_iterator = row.begin() + primary_key_starting_index;
  return std::vector<std::string>(key_starting_iterator, key_starting_iterator + primary_key.size());
}
