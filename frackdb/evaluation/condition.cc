#include "condition.hh"
#include "evaluate_condition_operand.hh"

Condition::Condition(condition_operand left, condition_operand right) : left(left), right(right) {
}

Condition::Condition(condition_operand left) : left(left) {
}

bool Condition::evaluate() const {
  return evaluate(Row());
}

bool And::evaluate(const Row& row) const {
  return boost::apply_visitor(Evaluate_condition_operand(row), left) && boost::apply_visitor(Evaluate_condition_operand(row), right);
}

bool Or::evaluate(const Row& row) const {
  return boost::apply_visitor(Evaluate_condition_operand(row), left) || boost::apply_visitor(Evaluate_condition_operand(row), right);
}

bool Not::evaluate(const Row& row) const {
  return !boost::apply_visitor(Evaluate_condition_operand(row), left);
}
