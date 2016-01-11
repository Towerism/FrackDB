//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

#include <memory>
#include <evaluation/evaluator.hh>
#include "query.hh"

class Select : public Query {
public:

  Select(Evaluator* evaluator);

  virtual Relation execute(const Relation& relation) override;

private:

  std::shared_ptr<Evaluator> evaluator;
};
