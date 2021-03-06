//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

#include <string>
#include "mpl_type_defs.hh"

class Attribute {
public:

  virtual bool is_type_compatible_with(const std::string& str) const = 0;

  virtual attribute_variant make_value(std::string str) const = 0;

  const std::string& get_name() const { return name; }

  virtual ~Attribute() = default;

protected:

  std::string name;
};
