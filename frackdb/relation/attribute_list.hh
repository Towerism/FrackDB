#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>
#include "attribute.hh"
#include "index_mapper.hh"

class Attribute_list {
public:

  Attribute_list(std::vector<Attribute*> attributes, std::vector<std::string> primary_key);

  std::string concatenate_key_for(const std::vector<std::string>& row) const;
  std::string concatenate_key(const std::vector<std::string>& key) const;

  void check_row(const std::vector<std::string>& row) const;

  std::vector<attribute_variant> make_variant_list_from_row(const std::vector<std::string>& row) const;

  std::map<std::string, int> get_index_map() const;

private:

  std::vector<std::shared_ptr<Attribute>> attributes;
  std::vector<std::string> primary_key;
  Index_mapper name_to_key_mapper;

  void check_primary_key();
  std::vector<std::string> calculate_key(const std::vector<std::string>& row) const;
};
