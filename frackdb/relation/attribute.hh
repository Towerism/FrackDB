#pragma once

#include <string>

class Attribute {
public:

  virtual bool is_type_compatible_with(const std::string& str) const = 0;

  const std::string& get_name() const { return name; }

  virtual ~Attribute() = default;

protected:

  std::string name;
};
