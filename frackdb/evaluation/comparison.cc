#include "comparison.hh"

Comparison::Comparison(operand left, Operator* op, operand right)
  : left(left), op(op), right(right) {
}

bool Comparison::evaluate() const {
  return op->evaluate(left, right);
}
