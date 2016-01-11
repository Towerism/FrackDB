//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include <boost/variant/multivisitors.hpp>
#include "comparison.hh"
#include "substitute.hh"

Comparison::Comparison(comparison_operand left, comparison_operand right)
  : left(left), right(right) {
}

bool Comparison::evaluate() const {
  return evaluate(Row());
}

bool Less_than::evaluate(const Row& row) const {
  return boost::apply_visitor(Substitute(row), left) < boost::apply_visitor(Substitute(row), right);
}

bool Greater_than::evaluate(const Row& row) const {
  return boost::apply_visitor(Substitute(row), left) > boost::apply_visitor(Substitute(row), right);
}

bool Equal::evaluate(const Row& row) const {
  return boost::apply_visitor(Substitute(row), left) == boost::apply_visitor(Substitute(row), right);
}

bool Less_equal::evaluate(const Row& row) const {
  return boost::apply_visitor(Substitute(row), left) <= boost::apply_visitor(Substitute(row), right);
}

bool Greater_equal::evaluate(const Row& row) const {
  return boost::apply_visitor(Substitute(row), left) >= boost::apply_visitor(Substitute(row), right);
}
