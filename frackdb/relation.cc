#include <algorithm>
#include "relation.hh"

Relation::Relation(std::string name, std::vector<std::string> attribute_names) : Relation(name, attribute_names, attribute_names) {
}

Relation::Relation(std::string name, std::vector<std::string> attribute_names, std::vector<std::string> primary_key)
  : name(name), attribute_names(attribute_names) {
  safe_set_primary_key(primary_key);
}

void Relation::safe_set_primary_key(std::vector<std::string> primary_key) {
  check_primary_key(primary_key);
  this->primary_key = primary_key;
}

void Relation::check_primary_key(std::vector<std::string>& primary_key) {
  primary_key_starting_iterator = std::search(attribute_names.begin(), attribute_names.end(),
                                     primary_key.begin(), primary_key.end());
  if (primary_key_starting_iterator == attribute_names.end())
    throw Primary_key_exception();
}

void Relation::add(std::vector<std::string> row) {
  std::vector<std::string> key = calculate_key(row);
  std::string concatenated_key = concatenate_key(key);
  rows[concatenated_key] = row;
}

std::string Relation::concatenate_key(const std::vector<std::string>& key) const {
  return std::accumulate(key.begin(), key.end(), std::string());
}

std::vector<std::string> Relation::calculate_key(const std::vector<std::string>& row) const {
  int primary_key_starting_index = primary_key_starting_iterator - attribute_names.begin();
  auto key_starting_iterator = row.begin() + primary_key_starting_index;
  return std::vector<std::string>(key_starting_iterator, key_starting_iterator + primary_key.size());
}

const std::vector<std::string>& Relation::get(const std::vector<std::string>& key) const {
  std::string concatenated_key = concatenate_key(key);
  return rows.at(concatenated_key);
}

const std::string& Relation::get_name() const {
  return name;
}

const std::vector<std::string>& Relation::get_attribute_names() const {
  return attribute_names;
}

const std::vector<std::string>& Relation::get_primary_key() const {
  return primary_key;
}
