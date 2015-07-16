#include <algorithm>
#include "relation.hh"

Relation::Relation(std::string name, std::vector<std::string> attribute_names) : Relation(name, attribute_names, attribute_names) {
}

Relation::Relation(std::string name, std::vector<std::string> attribute_names, std::vector<std::string> primary_key)
  : name(name), attribute_list(attribute_names) {
  attribute_list.safe_set_primary_key(primary_key);
}

void Relation::add(std::vector<std::string> row) {
  attribute_list.check_row_size(row);
  std::string concatenated_key = attribute_list.concatenate_key_for(row);
  rows[concatenated_key] = row;
}

const std::vector<std::string>& Relation::get(const std::vector<std::string>& key) const {
  std::string concatenated_key = attribute_list.concatenate_key(key);
  return rows.at(concatenated_key);
}
