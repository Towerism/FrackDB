#pragma once

#include <boost/variant.hpp>
#include <memory>
#include "comparison.hh"

class Condition;
typedef boost::variant<std::shared_ptr<Comparison>, std::shared_ptr<Condition>, bool> condition_operand;

class Condition {
public:

  Condition(condition_operand left, condition_operand right) : left(left), right(right) { }
  Condition(condition_operand left) : left(left) { }

  virtual bool evaluate() const = 0;

  virtual ~Condition() = default;

protected:

  condition_operand left, right;
};

class And : public Condition {
public:

  And(condition_operand left, condition_operand right) : Condition(left, right) { }

  virtual bool evaluate() const override;
};

class Or : public Condition {
public:

  Or(condition_operand left, condition_operand right) : Condition(left, right) { }

  virtual bool evaluate() const override;
};

class Not : public Condition {
public:

  Not(condition_operand left) : Condition(left) { }

  virtual bool evaluate() const override;
};
