#pragma once

#include <relation/relation.hh>

class Query {
public:

  virtual Relation execute(const Relation& relation) = 0;

  virtual ~Query() = default;
};
