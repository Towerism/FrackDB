#include "comparison.hh"
#include "evaluate_comparison.hh"

bool Evaluate_comparison::operator()(const Comparison<Operator::Less_than>& comparison) const {
  return comparison.left < comparison.right;
}

bool Evaluate_comparison::operator()(const Comparison<Operator::Greater_than>& comparison) const {
  return comparison.left > comparison.right;
}

bool Evaluate_comparison::operator()(const Comparison<Operator::Equal>& comparison) const {
  return comparison.left == comparison.right;
}

bool Evaluate_comparison::operator()(const Comparison<Operator::Less_equal>& comparison) const {
  return comparison.left <= comparison.right;
}

bool Evaluate_comparison::operator()(const Comparison<Operator::Greater_equal>& comparison) const {
  return comparison.left >= comparison.right;
}
