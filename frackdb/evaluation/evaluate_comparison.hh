#pragma once

#include "comparison.hh"

template <Operator op>
class Comparison;

class Evaluate_comparison : boost::static_visitor<bool> {
public:

  bool operator()(const Comparison<Operator::Less_than>& comparison) const;

  bool operator()(const Comparison<Operator::Greater_than>& comparison) const;

  bool operator()(const Comparison<Operator::Equal>& comparison) const;

  bool operator()(const Comparison<Operator::Less_equal>& comparison) const;

  bool operator()(const Comparison<Operator::Greater_equal>& comparison) const;
};
