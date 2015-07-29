#include "identifier.hh"

Identifier::Identifier(std::string name) : name(name) {
}

attribute_variant Identifier::substitute_value_from(const Row& row) const {
  return attribute_variant(row.get_variant(name));
}

