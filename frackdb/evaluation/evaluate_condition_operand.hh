//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "condition.hh"

class Evaluate_condition_operand : boost::static_visitor<bool> {
public:

  Evaluate_condition_operand(const Row& row) : row(row), boost::static_visitor<bool>::static_visitor() {
  }

  bool operator()(std::shared_ptr<Comparison> comparison) const {
    return comparison->evaluate(row);
  }

  bool operator()(std::shared_ptr<Condition> condition) const {
    return condition->evaluate(row);
  }

  bool operator()(bool boolean) const {
    return boolean;
  }

private:

  const Row& row;
};
