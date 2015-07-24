#include <boost/variant.hpp>
#include <string>

typedef boost::variant<int, std::string> operand;

class Operator {
public:

  virtual bool evaluate(operand left, operand right) const = 0;

  virtual ~Operator() = default;
};

class Less_than : public Operator {
public:

  virtual bool evaluate(operand left, operand right) const override {
    return left < right;
  }
};

class Greater_than : public Operator {
public:

  virtual bool evaluate(operand left, operand right) const override {
    return left > right;
  }
};

class Equal : public Operator {
public:

  virtual bool evaluate(operand left, operand right) const override {
    return left == right;
  }
};
