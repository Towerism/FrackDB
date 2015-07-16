#pragma once

#include <string>
#include <vector>
#include <util/exception/define_exception.hh>

class Attribute_list {
public:

  Attribute_list(std::vector<std::string> names);

  void safe_set_primary_key(std::vector<std::string> primary_key);
  std::string concatenate_key_for(const std::vector<std::string>& row) const;
  std::string concatenate_key(const std::vector<std::string>& key) const;

  void check_row_size(const std::vector<std::string>& row) const;

  DEFINE_EXCEPTION(Primary_key_exception, Attribute_list);
  DEFINE_EXCEPTION(Row_size_exception, Attribute_list);

private:

  std::vector<std::string> names;
  std::vector<std::string> primary_key;
  std::vector<std::string>::iterator primary_key_starting_iterator;

  void check_primary_key(std::vector<std::string>& primary_key);
  std::vector<std::string> calculate_key(const std::vector<std::string>& row) const;
};
