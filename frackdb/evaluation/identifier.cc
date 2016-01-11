//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "identifier.hh"

Identifier::Identifier(std::string name) : name(name) {
}

attribute_variant Identifier::substitute_value_from(const Row& row) const {
  return attribute_variant(row.get_variant(name));
}

