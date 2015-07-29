#include "relation.hh"

Relation::Relation(std::string name, Attribute_list attribute_list)
  : name(name), attribute_list(attribute_list) {
}

void Relation::add(std::vector<std::string> row) {
  attribute_list.check_row(row);
  std::string concatenated_key = attribute_list.concatenate_key_for(row);
  rows[concatenated_key] = Row(attribute_list.make_variant_list_from_row(row), attribute_list.get_index_map());
}

const Row& Relation::get(const std::vector<std::string>& key) const {
  std::string concatenated_key = attribute_list.concatenate_key(key);
  return rows.at(concatenated_key);
}

void Relation::remove_if_not(std::shared_ptr<Evaluator> evaluator) {
  for (auto key_row_pair : rows)
    if (!evaluator->evaluate(key_row_pair.second))
      rows.erase(key_row_pair.first);
}

int Relation::size() const {
  return rows.size();
}
