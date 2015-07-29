#include <boost/variant/multivisitors.hpp>
#include "comparison.hh"

class Substitute : public boost::static_visitor<basic_comparison_operand> {
public:

  Substitute(const Row& row) : row(row), boost::static_visitor<basic_comparison_operand>::static_visitor() { }

  basic_comparison_operand operator()(int value) const {
    return value;
  }

  basic_comparison_operand operator()(const std::string& value) const {
    return value;
  }

  basic_comparison_operand operator()(const Identifier& identifier) const {
    return identifier.substitute_value_from(row);
  }

private:

  const Row& row;
};

Comparison::Comparison(comparison_operand left, comparison_operand right)
  : left(left), right(right) {
}

bool Less_than::evaluate() const {
  return evaluate(Row());
}

bool Less_than::evaluate(const Row& row) const {
  return boost::apply_visitor(Substitute(row), left) < boost::apply_visitor(Substitute(row), right);
}

bool Greater_than::evaluate() const {
  return evaluate(Row());
}

bool Greater_than::evaluate(const Row& row) const {
  return boost::apply_visitor(Substitute(row), left) > boost::apply_visitor(Substitute(row), right);
}

bool Equal::evaluate() const {
  return evaluate(Row());
}

bool Equal::evaluate(const Row& row) const {
  return boost::apply_visitor(Substitute(row), left) == boost::apply_visitor(Substitute(row), right);
}

bool Less_equal::evaluate() const {
  return evaluate(Row());
}

bool Less_equal::evaluate(const Row& row) const {
  return boost::apply_visitor(Substitute(row), left) <= boost::apply_visitor(Substitute(row), right);
}

bool Greater_equal::evaluate() const {
  return evaluate(Row());
}

bool Greater_equal::evaluate(const Row& row) const {
  return boost::apply_visitor(Substitute(row), left) >= boost::apply_visitor(Substitute(row), right);
}
