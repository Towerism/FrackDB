#include <algorithm>
#include "primary_key_checker.hh"

Primary_key_checker::Primary_key_checker(const std::vector<std::string>& names, const std::vector<std::string>& primary_key)
  : names(names), primary_key(primary_key) {
}

// TODO: refactor
void Primary_key_checker::check() const {
  auto primary_key_iterator = primary_key.begin();
  for (auto names_iterator = names.begin(); primary_key_iterator != primary_key.end(); ++names_iterator, ++primary_key_iterator) {
    auto found = std::find(names_iterator, names.end(), *primary_key_iterator);
    if (found == names.end() || names_iterator == names.end())
      throw Primary_key_exception();
  }
}
