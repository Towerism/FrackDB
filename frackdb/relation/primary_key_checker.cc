#include <algorithm>
#include "names_extractor.hh"
#include "primary_key_checker.hh"

Primary_key_checker::Primary_key_checker(const std::vector<std::shared_ptr<Attribute>>& attributes, const std::vector<std::string>& primary_key)
  : names(Names_extractor::extract(attributes)), primary_key(primary_key), names_iterator(names.begin()), primary_key_iterator(primary_key.begin()) {
}

void Primary_key_checker::check() {
  while (primary_key_iterator != primary_key.end())
    check_next_key_word_exists_in_names();
}

void Primary_key_checker::check_next_key_word_exists_in_names() {
  auto found = std::find(names_iterator, names.cend(), *primary_key_iterator);
  check_key_word_exists_in_names(found);
  advance_iterators();
}

void Primary_key_checker::check_key_word_exists_in_names(std::vector<std::string>::const_iterator iterator) {
  if (iterator == names.end() || names_iterator == names.end())
    throw Primary_key_exception();
}

void Primary_key_checker::advance_iterators() {
  ++names_iterator;
  ++primary_key_iterator;
}
