#pragma once

#include <util/exception/define_exception.hh>
#include "attribute_list.hh"

class Row_checker {
public:
  Row_checker(const std::vector<std::shared_ptr<Attribute>>& attributes,
              const std::vector<std::string>& row);

  void check() const;

  DEFINE_EXCEPTION(Row_size_exception, Attribute_list);
  DEFINE_EXCEPTION(Type_match_exception, Attribute_list);
  DEFINE_EXCEPTION(No_attribute_exception, Attribute_list);

private:

  const std::vector<std::shared_ptr<Attribute>>& attributes;
  const std::vector<std::string>& row;

  void check_size() const;
  void check_types() const;
  bool types_are_matching() const;
};
