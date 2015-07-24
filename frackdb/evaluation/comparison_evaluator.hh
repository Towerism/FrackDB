#pragma once

#include "comparison.hh"
#include "evaluate_comparison.hh"

class Comparison_evaluator {
public:

  typedef boost::variant<
    Comparison<Operator::Less_than>,
    Comparison<Operator::Greater_than>,
    Comparison<Operator::Equal>
  > comparison_variant;

  static bool evaluate(const comparison_variant& comparison);

private:
};

bool Comparison_evaluator::evaluate(const comparison_variant& comparison) {
  return boost::apply_visitor(Evaluate_comparison(), comparison);
}
