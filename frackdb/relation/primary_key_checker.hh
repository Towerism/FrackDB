#include <memory>
#include <string>
#include <vector>
#include <util/exception/define_exception.hh>

class Primary_key_checker {
public:

  Primary_key_checker(const std::vector<std::string>& names, const std::vector<std::string>& primary_key);

  void check() ;

  DEFINE_EXCEPTION(Primary_key_exception, Attribute_list);

private:

  const std::vector<std::string>& names;
  const std::vector<std::string>& primary_key;

  std::vector<std::string>::const_iterator names_iterator;
  std::vector<std::string>::const_iterator primary_key_iterator;

  void check_next_key_word_exists_in_names();
  void check_key_word_exists_in_names(std::vector<std::string>::const_iterator iterator);
  void advance_iterators();
};
