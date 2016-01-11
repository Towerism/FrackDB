//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include <boost/variant/multivisitors.hpp>
#include "comparison.hh"

class Substitute : public boost::static_visitor<basic_comparison_operand> {
public:

  Substitute(const Row& row) : row(row), boost::static_visitor<basic_comparison_operand>::static_visitor() {
  }
  basic_comparison_operand operator()(int value) const {
    return value;
  }

  basic_comparison_operand operator()(const std::string& value) const {
    return value;
  }

  basic_comparison_operand operator()(const Identifier& identifier) const {
    return identifier.substitute_value_from(row);
  }

private:

  const Row& row;
};
