#include "comparison.hh"

Comparison::Comparison(operand left, operand right)
  : left(left), right(right) {
}

bool Less_than::evaluate() const {
  return left < right;
}

bool Greater_than::evaluate() const {
  return left > right;
}

bool Equal::evaluate() const {
  return left == right;
}

bool Less_equal::evaluate() const {
  return left <= right;
}

bool Greater_equal::evaluate() const {
  return left >= right;
}
