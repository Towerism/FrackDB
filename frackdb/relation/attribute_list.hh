#pragma once

#include <string>
#include <vector>

class Attribute_list {
public:

  Attribute_list(std::vector<std::string> names);

  void safe_set_primary_key(std::vector<std::string> primary_key);
  std::string concatenate_key_for(const std::vector<std::string>& row) const;
  std::string concatenate_key(const std::vector<std::string>& key) const;

  struct Primary_key_exception : public std::exception {
    virtual const char* what() const noexcept {
      return "Primary_key_exception";
    }
  };

private:

  std::vector<std::string> names;
  std::vector<std::string> primary_key;
  std::vector<std::string>::iterator primary_key_starting_iterator;

  void check_primary_key(std::vector<std::string>& primary_key);
  std::vector<std::string> calculate_key(const std::vector<std::string>& row) const;
};
