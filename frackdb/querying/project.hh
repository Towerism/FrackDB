//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "query.hh"
#include <vector>
#include <string>

class Project : public Query {
public:

  Project(std::vector<std::string> attributes);

  virtual Relation execute(const Relation& relation) override;

};
