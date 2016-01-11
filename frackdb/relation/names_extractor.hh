//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include <memory>
#include <vector>
#include "attribute.hh"

class Names_extractor {
public:

  static std::vector<std::string> extract(const std::vector<std::shared_ptr<Attribute>>& attribute_vec);
};
