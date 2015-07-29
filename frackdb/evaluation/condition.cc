#include "condition.hh"

class Evaluate_condition_operand : boost::static_visitor<bool> {
public:

  Evaluate_condition_operand(const Row& row) : row(row), boost::static_visitor<bool>::static_visitor() { }

  bool operator()(std::shared_ptr<Comparison> comparison) const { return comparison->evaluate(row); }
  bool operator()(std::shared_ptr<Condition> condition) const { return condition->evaluate(row); }
  bool operator()(bool boolean) const { return boolean; }

private:

  const Row& row;
};

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
