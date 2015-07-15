#include <exception>
#include <map>
#include <string>
#include <vector>

class Relation {
public:

  Relation(std::string name, std::vector<std::string> attribute_names);
  Relation(std::string name, std::vector<std::string> attribute_names, std::vector<std::string> primary_key);

  void add(std::vector<std::string> row);
  const std::vector<std::string>& get(const std::vector<std::string>& key) const;

  const std::string& get_name() const;
  const std::vector<std::string>& get_attribute_names() const;
  const std::vector<std::string>& get_primary_key() const;

  struct Primary_key_exception : public std::exception {
    virtual const char* what() const noexcept {
      return "Primary_key_exception";
    }
  };

private:

  std::string name;
  std::vector<std::string> attribute_names;
  std::vector<std::string> primary_key;
  std::map<std::string, std::vector<std::string>> rows;
  std::vector<std::string>::iterator primary_key_starting_iterator;

  void safe_set_primary_key(std::vector<std::string> primary_key);
  void check_primary_key(std::vector<std::string>& primary_key);
};
