#include <boost/mpl/vector.hpp>
#include <boost/variant.hpp>
#include <string>

typedef boost::mpl::vector<int, std::string> attribute_types;
typedef boost::make_variant_over<attribute_types>::type attribute_variant;
