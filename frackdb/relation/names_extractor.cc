#include "names_extractor.hh"

std::vector<std::string> Names_extractor::extract(const std::vector<std::shared_ptr<Attribute>>& attribute_vec) {
  std::vector<std::string> names;
  for (auto attribute : attribute_vec)
    names.push_back(attribute->get_name());
  return names;
}
