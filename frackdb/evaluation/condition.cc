#include "condition.hh"
#include "evaluate_condition_operand.hh"

Condition::Condition(condition_operand left, condition_operand right) : left(left), right(right) {
}

Condition::Condition(condition_operand left) : left(left) {
}

bool Condition::evaluate() const {
  return evaluate(Row());
}

bool Condition::evaluate_left(const Row& row) const {
  return boost::apply_visitor(Evaluate_condition_operand(row), left);
}

bool Condition::evaluate_right(const Row& row) const {
  return boost::apply_visitor(Evaluate_condition_operand(row), right);
}

bool And::evaluate(const Row& row) const {
  return evaluate_left(row) && evaluate_right(row);
}

bool Or::evaluate(const Row& row) const {
  return evaluate_left(row) || evaluate_right(row);
}

bool Not::evaluate(const Row& row) const {
  return !evaluate_left(row);
}
