//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  FrackDB is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include <boost/mpl/vector.hpp>
#include <boost/variant.hpp>
#include <string>

typedef boost::mpl::vector<int, std::string> attribute_types;
typedef boost::make_variant_over<attribute_types>::type attribute_variant;
