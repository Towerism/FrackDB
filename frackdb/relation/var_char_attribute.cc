#include "var_char_attribute.hh"

Var_char_attribute::Var_char_attribute(std::string name, int char_limit) : char_limit(char_limit) {
  this->name = name;
}

bool Var_char_attribute::is_type_compatible_with(const std::string& str) const {
  return str.size() <= char_limit;
}
