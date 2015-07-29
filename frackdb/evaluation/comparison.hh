#pragma once

#include <boost/variant.hpp>
#include <string>
#include <relation/row.hh>
#include "mpl_type_defs.hh"
#include "evaluator.hh"
#include "identifier.hh"

typedef boost::mpl::push_back<basic_comparison_operand_types, Identifier>::type comparison_operand_types;
typedef boost::make_variant_over<comparison_operand_types>::type comparison_operand;

class Comparison : public Evaluator {
public:

  Comparison(comparison_operand left, comparison_operand right);

  virtual bool evaluate() const override;
  virtual bool evaluate(const Row& row) const override = 0;

  virtual ~Comparison() = default;

protected:

  comparison_operand left, right;
};

class Less_than : public Comparison {
public:
  using Comparison::Comparison;

  virtual bool evaluate(const Row& row) const override;
};

class Greater_than : public Comparison {
public:
  using Comparison::Comparison;

  virtual bool evaluate(const Row& row) const override;
};

class Equal : public Comparison {
public:
  using Comparison::Comparison;

  virtual bool evaluate(const Row& row) const override;
};

class Less_equal : public Comparison {
public:
  using Comparison::Comparison;

  virtual bool evaluate(const Row& row) const override;
};

class Greater_equal : public Comparison {
public:
  using Comparison::Comparison;

  virtual bool evaluate(const Row& row) const override;
};
