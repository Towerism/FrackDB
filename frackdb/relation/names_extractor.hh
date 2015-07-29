#include <memory>
#include <vector>
#include "attribute.hh"

class Names_extractor {
public:

  static std::vector<std::string> extract(const std::vector<std::shared_ptr<Attribute>>& attribute_vec);
};
