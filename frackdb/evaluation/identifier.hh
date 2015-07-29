#include <string>
#include <relation/row.hh>
#include "mpl_type_defs.hh"

// NEED ROWS TO CARRY TYPE INFO!!

class Identifier {
public:

  Identifier(std::string name = "");

  attribute_variant substitute_value_from(const Row& row) const;

private:

  std::string name;
};
