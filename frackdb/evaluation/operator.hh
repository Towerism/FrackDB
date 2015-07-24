#pragma once

#include <boost/variant.hpp>
#include <string>

typedef boost::variant<int, std::string> operand;

enum class Operator {
  Less_than, Greater_than, Equal
};
