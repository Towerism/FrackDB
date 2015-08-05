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
