#pragma once

#include <map>
#include <string>
#include <vector>
#include "attribute_list.hh"

class Relation {
public:

  Relation(std::string name, Attribute_list attribute_list);

  void add(std::vector<std::string> row);
  const std::vector<std::string>& get(const std::vector<std::string>& key) const;

private:

  std::string name;
  Attribute_list attribute_list;

  std::map<std::string, std::vector<std::string>> rows;
};
