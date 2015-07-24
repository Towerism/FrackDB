#include <boost/variant.hpp>
#include <memory>
#include <string>
#include "operator.hh"

class Comparison {
public:

  Comparison(operand left, Operator* op, operand right);

  bool evaluate() const;

private:

  boost::variant<int, std::string> left;
  std::unique_ptr<Operator> op;
  boost::variant<int, std::string> right;
};
