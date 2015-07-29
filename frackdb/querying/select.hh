#pragma once

#include <memory>
#include <evaluation/evaluator.hh>
#include "query.hh"

class Select : public Query {
public:

  Select(Evaluator* evaluator);

  virtual Relation execute(const Relation& relation) override;

private:

  std::shared_ptr<Evaluator> evaluator;
};
