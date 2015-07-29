#pragma once

#include "attribute.hh"

class Integer_attribute : public Attribute {
public:

  Integer_attribute(std::string name);

  virtual bool is_type_compatible_with(const std::string& str) const override;

  virtual attribute_variant make_value(std::string str) const override;

private:

  bool is_integer(const std::string& str) const;
};
