//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include <memory>
#include <string>
#include <vector>
#include <util/exception/define_exception.hh>

class Primary_key_checker {
public:

  Primary_key_checker(const std::vector<std::shared_ptr<Attribute>>& attributes, const std::vector<std::string>& primary_key);

  void check() ;

  DEFINE_EXCEPTION(Primary_key_exception, Attribute_list);

private:

  std::vector<std::string> names;
  const std::vector<std::string>& primary_key;

  std::vector<std::string>::const_iterator names_iterator;
  std::vector<std::string>::const_iterator primary_key_iterator;

  void check_next_key_word_exists_in_names();
  void check_key_word_exists_in_names(std::vector<std::string>::const_iterator iterator);
  void advance_iterators();
};
