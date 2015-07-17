#pragma once

#include <map>
#include <string>
#include <vector>
#include "attribute_list.hh"

class Relation {
public:

  Relation(std::string name, Attribute_list attribute_list, std::vector<std::string> primary_key);

  void add(std::vector<std::string> row);
  const std::vector<std::string>& get(const std::vector<std::string>& key) const;

  const std::string& get_name() const;
  const std::vector<std::string>& get_attribute_names() const;
  const std::vector<std::string>& get_primary_key() const;

private:

  std::string name;
  Attribute_list attribute_list;

  std::map<std::string, std::vector<std::string>> rows;
};
