//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

#include <relation/row.hh>

class Evaluator {
public:

  virtual bool evaluate() const = 0;
  virtual bool evaluate(const Row& row) const = 0;

  virtual ~Evaluator() = default;
};
