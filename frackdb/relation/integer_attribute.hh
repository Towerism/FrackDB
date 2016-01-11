//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

#include "attribute.hh"

class Integer_attribute : public Attribute {
public:

  Integer_attribute(std::string name);

  virtual bool is_type_compatible_with(const std::string& str) const override;

  virtual attribute_variant make_value(std::string str) const override;

private:

  bool is_integer(const std::string& str) const;
};
