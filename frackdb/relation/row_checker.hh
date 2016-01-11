//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

#include <util/exception/define_exception.hh>
#include "attribute_list.hh"

class Row_checker {
public:
  Row_checker(const std::vector<std::shared_ptr<Attribute>>& attributes,
              const std::vector<std::string>& row);

  void check() const;

  DEFINE_EXCEPTION(Row_size_exception, Attribute_list);
  DEFINE_EXCEPTION(Type_match_exception, Attribute_list);

private:

  const std::vector<std::shared_ptr<Attribute>>& attributes;
  const std::vector<std::string>& row;

  void check_size() const;
  void check_types() const;
  bool types_are_matching() const;
};
