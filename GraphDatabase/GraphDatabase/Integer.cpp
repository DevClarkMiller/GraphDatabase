#include "Integer.hpp"
using namespace std;

Property::string_type Integer::str() const {
	return Property::string_type(to_string(value_));
}