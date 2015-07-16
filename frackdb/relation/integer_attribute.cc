#include <boost/lexical_cast.hpp>
#include "integer_attribute.hh"

Integer_attribute::Integer_attribute(std::string value) {
}

bool Integer_attribute::is_type_compatible_with(const std::string& str) const {
  return is_integer(str);
}

bool Integer_attribute::is_integer(const std::string& str) const {
  try { boost::lexical_cast<int>(str); }
  catch (const boost::bad_lexical_cast&) { return false; }
  return true;
}
