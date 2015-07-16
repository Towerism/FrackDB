#include "var_char_attribute.hh"

Var_char_attribute::Var_char_attribute(std::string value, int char_limit) : char_limit(char_limit) {
}

bool Var_char_attribute::is_type_compatible_with(const std::string& str) const {
  return str.size() <= char_limit;
}
