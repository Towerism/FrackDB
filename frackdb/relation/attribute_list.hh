#pragma once

#include <memory>
#include <string>
#include <vector>
#include <util/exception/define_exception.hh>
#include "var_char_attribute.hh"
#include "integer_attribute.hh"

class Attribute_list {
public:

  Attribute_list(std::vector<Attribute*> attributes);

  void safe_set_primary_key(std::vector<std::string> primary_key);
  std::string concatenate_key_for(std::vector<std::string>& row) const;
  std::string concatenate_key(const std::vector<std::string>& key) const;

  void check_row(const std::vector<std::string>& row) const;

  DEFINE_EXCEPTION(Primary_key_exception, Attribute_list);

private:

  std::vector<std::shared_ptr<Attribute>> attributes;
  std::vector<std::string> names;
  std::vector<std::string> primary_key;
  std::vector<std::string>::iterator primary_key_starting_iterator;

  void init_attribute_ptrs(std::vector<Attribute*> attributes);
  void init_names();
  void check_primary_key(std::vector<std::string>& primary_key);
  std::vector<std::string> calculate_key(const std::vector<std::string>& row) const;
};
