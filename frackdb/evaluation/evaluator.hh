#pragma once

#include <relation/row.hh>

class Evaluator {
public:

  virtual bool evaluate() const = 0;
  virtual bool evaluate(const Row& row) const = 0;

  virtual ~Evaluator() = default;
};
