//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include <algorithm>
#include "select.hh"

Select::Select(Evaluator* evaluator) : evaluator(evaluator) {
}

Relation Select::execute(const Relation& relation) {
  Relation view = relation;
  view.remove_if_not(evaluator);
  return view;
}
