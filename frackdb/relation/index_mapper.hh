#pragma once

#include <string>
#include <vector>

class Index_mapper {
public:

  Index_mapper(const std::vector<std::string>& from_vector, const std::vector<std::string>& to_vector);

  void init();
  int get(int i) const;

private:

  std::vector<int> mapping;
  const std::vector<std::string>& from_vector;
  const std::vector<std::string>& to_vector;

  void init_mapping();
  void map_next_index_to(int index);
  void map_index(int from, int to);
};
