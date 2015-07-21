#pragma once

#include <string>
#include <vector>

class Index_mapper {
public:

  Index_mapper(std::vector<std::string> from_vector, std::vector<std::string> to_vector);

  void init();
  int get(int i) const;

private:

  std::vector<int> mapping;
  std::vector<std::string> from_vector;
  std::vector<std::string> to_vector;

  void init_mapping();
  void map_next_index_to(int index);
  void map_index(int from, int to);
};
