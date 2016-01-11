//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include <exception>

#define DEFINE_EXCEPTION(NAME, CLASS) \
  struct NAME : public std::exception { \
    virtual const char* what() const noexcept { \
      return #CLASS ": " #NAME; \
    } \
  }
