//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include <string>
#include <relation/row.hh>
#include "mpl_type_defs.hh"

class Identifier {
public:

  Identifier(std::string name = "");

  attribute_variant substitute_value_from(const Row& row) const;

private:

  std::string name;
};
