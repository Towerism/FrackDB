#pragma once

#include <map>
#include <string>
#include <vector>
#include <evaluation/evaluator.hh>
#include "attribute_list.hh"
#include "row.hh"

class Relation {
public:

  Relation(std::string name, Attribute_list attribute_list);

  void add(std::vector<std::string> row);
  const Row& get(const std::vector<std::string>& key) const;

  void remove_if_not(std::shared_ptr<Evaluator> evaluator);

  int size() const;

private:

  std::string name;
  Attribute_list attribute_list;

  std::map<std::string, Row> rows;
};
