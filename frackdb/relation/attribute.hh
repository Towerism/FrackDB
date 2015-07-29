#pragma once

#include <string>
#include "mpl_type_defs.hh"

class Attribute {
public:

  virtual bool is_type_compatible_with(const std::string& str) const = 0;

  virtual attribute_variant make_value(std::string str) const = 0;

  const std::string& get_name() const { return name; }

  virtual ~Attribute() = default;

protected:

  std::string name;
};
