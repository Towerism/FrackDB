#include "relation.hh"

Relation::Relation(std::string name, Attribute_list attribute_list, std::vector<std::string> primary_key)
  : name(name), attribute_list(attribute_list) {
  this->attribute_list.safe_set_primary_key(primary_key);
}

void Relation::add(std::vector<std::string> row) {
  attribute_list.check_row(row);
  std::string concatenated_key = attribute_list.concatenate_key_for(row);
  rows[concatenated_key] = row;
}

const std::vector<std::string>& Relation::get(const std::vector<std::string>& key) const {
  std::string concatenated_key = attribute_list.concatenate_key(key);
  return rows.at(concatenated_key);
}
