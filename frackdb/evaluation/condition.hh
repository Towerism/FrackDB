//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

#include <boost/variant.hpp>
#include <memory>
#include <relation/row.hh>
#include "comparison.hh"
#include "evaluator.hh"

class Condition;
typedef boost::variant<std::shared_ptr<Comparison>, std::shared_ptr<Condition>, bool> condition_operand;

class Condition : public Evaluator {
public:

  Condition(condition_operand left, condition_operand right);
  Condition(condition_operand left);

  virtual bool evaluate() const override;
  virtual bool evaluate(const Row& row) const override = 0;

  virtual ~Condition() = default;

protected:

  condition_operand left, right;

  bool evaluate_left(const Row& row) const;
  bool evaluate_right(const Row& row) const;
};

class And : public Condition {
public:

  And(condition_operand left, condition_operand right) : Condition(left, right) { }

  virtual bool evaluate(const Row& row) const override;
};

class Or : public Condition {
public:

  Or(condition_operand left, condition_operand right) : Condition(left, right) { }

  virtual bool evaluate(const Row& row) const override;
};

class Not : public Condition {
public:

  Not(condition_operand left) : Condition(left) { }

  virtual bool evaluate(const Row& row) const override;
};
