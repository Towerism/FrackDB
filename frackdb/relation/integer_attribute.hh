#pragma once

#include "attribute.hh"

class Integer_attribute : public Attribute {
public:

  Integer_attribute(std::string value);

  virtual bool is_type_compatible_with(const std::string& str) const override;

private:

  bool is_integer(const std::string& str) const;
};
