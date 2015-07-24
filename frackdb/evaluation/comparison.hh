#pragma once

#include <boost/variant.hpp>
#include <boost/mpl/vector.hpp>
#include <memory>
#include <string>
#include "operator.hh"

template <Operator op>
class Comparison {
public:

  Comparison(operand left, operand right);

  operand left;
  operand right;
};

template <Operator op>
Comparison<op>::Comparison(operand left, operand right) : left(left), right(right) {
}
