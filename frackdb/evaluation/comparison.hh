#pragma once

#include <boost/variant.hpp>
#include <string>

typedef boost::variant<int, std::string> comparison_operand;

class Comparison {
public:

  Comparison(comparison_operand left, comparison_operand right);

  virtual bool evaluate() const = 0;

  virtual ~Comparison() = default;

protected:

  comparison_operand left, right;
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
