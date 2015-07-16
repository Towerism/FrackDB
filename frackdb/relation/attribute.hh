#pragma once

#include <string>

class Attribute {
public:

  virtual bool is_type_compatible_with(const std::string& str) const = 0;

  virtual ~Attribute() = default;
};
