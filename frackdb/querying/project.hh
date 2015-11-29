#include "query.hh"
#include <vector>
#include <string>

class Project : public Query {
public:

  Project(std::vector<std::string> attributes);

  virtual Relation execute(const Relation& relation) override;

};
