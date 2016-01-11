//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

#include <relation/relation.hh>

class Query {
public:

  virtual Relation execute(const Relation& relation) = 0;

  virtual ~Query() = default;
};
