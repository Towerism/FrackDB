#include <string>
#include <relation/row.hh>
#include "mpl_type_defs.hh"

// NEED ROWS TO CARRY TYPE INFO!!

class Identifier {
public:

  Identifier(std::string name = "") : name(name) { }

  attribute_variant evaluate(const Row& row) const {
    return attribute_variant(row.get_variant(name));
  }

private:

  std::string name;
};
