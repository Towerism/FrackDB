#include <string>
#include <relation/row.hh>
#include "mpl_type_defs.hh"

class Identifier {
public:

  Identifier(std::string name = "");

  attribute_variant substitute_value_from(const Row& row) const;

private:

  std::string name;
};
