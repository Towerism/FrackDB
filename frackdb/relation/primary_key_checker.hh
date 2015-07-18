#include <memory>
#include <string>
#include <vector>
#include <util/exception/define_exception.hh>

class Primary_key_checker {
public:

  Primary_key_checker(const std::vector<std::string>& names, const std::vector<std::string>& primary_key);

  void check() const;

  DEFINE_EXCEPTION(Primary_key_exception, Attribute_list);

private:

  const std::vector<std::string>& names;
  const std::vector<std::string>& primary_key;

};
