#include "condition.hh"

class Evaluate_condition_operand : boost::static_visitor<bool> {
public:

  bool operator()(std::shared_ptr<Comparison> comparison) const { return comparison->evaluate(); }
  bool operator()(std::shared_ptr<Condition> condition) const { return condition->evaluate(); }
  bool operator()(bool boolean) const { return boolean; }
};

bool And::evaluate() const {
  return boost::apply_visitor(Evaluate_condition_operand(), left) && boost::apply_visitor(Evaluate_condition_operand(), right);
}

bool Or::evaluate() const {
  return boost::apply_visitor(Evaluate_condition_operand(), left) || boost::apply_visitor(Evaluate_condition_operand(), right);
}

bool Not::evaluate() const {
  return !boost::apply_visitor(Evaluate_condition_operand(), left);
}
