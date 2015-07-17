#pragma once

#include "attribute.hh"

class Var_char_attribute : public Attribute {
public:

  Var_char_attribute(std::string name, int char_limit);

  virtual bool is_type_compatible_with(const std::string& str) const override;

private:

  int char_limit;
};
