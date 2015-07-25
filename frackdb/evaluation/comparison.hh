#pragma once

#include <boost/variant.hpp>
#include <memory>
#include <string>

typedef boost::variant<int, std::string> operand;

class Comparison {
public:

  Comparison(operand left, operand right);

  virtual bool evaluate() const = 0;

  virtual ~Comparison() = default;

protected:

  operand left, right;
};

class Less_than : public Comparison {
public:
  using Comparison::Comparison;

  virtual bool evaluate() const override;
};

class Greater_than : public Comparison {
public:
  using Comparison::Comparison;

  virtual bool evaluate() const override;
};

class Equal : public Comparison {
public:
  using Comparison::Comparison;

  virtual bool evaluate() const override;
};

class Less_equal : public Comparison {
public:
  using Comparison::Comparison;

  virtual bool evaluate() const override;
};

class Greater_equal : public Comparison {
public:
  using Comparison::Comparison;
virtual bool evaluate() const override;
};
