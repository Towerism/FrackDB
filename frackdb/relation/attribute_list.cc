#include <algorithm>
#include "attribute_list.hh"
#include "row_checker.hh"

Attribute_list::Attribute_list(std::vector<Attribute*> attributes, std::vector<std::string> primary_key) : name_to_key_mapper(names, primary_key) {
  init_attribute_ptrs(attributes);
  init_names();
  safe_set_primary_key(primary_key);
  name_to_key_mapper.init();
}

void Attribute_list::init_attribute_ptrs(std::vector<Attribute*> attributes) {
  for (auto attribute : attributes)
    this->attributes.emplace_back(attribute);
}

void Attribute_list::init_names() {
  for (auto attribute : attributes)
    names.push_back(attribute->get_name());
}

void Attribute_list::safe_set_primary_key(std::vector<std::string> primary_key) {
  this->primary_key = primary_key;
  check_primary_key();
}

// TODO: refactor
void Attribute_list::check_primary_key() {
  auto primary_key_iterator = primary_key.begin();
  for (auto names_iterator = names.begin(); primary_key_iterator != primary_key.end(); ++names_iterator, ++primary_key_iterator) {
    auto found = std::find(names_iterator, names.end(), *primary_key_iterator);
    if (found == names.end() || names_iterator == names.end())
      throw Primary_key_exception();
  }
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
