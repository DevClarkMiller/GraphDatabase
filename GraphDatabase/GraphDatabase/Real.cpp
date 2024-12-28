#include "Real.hpp"
using namespace std;

Property::string_type Real::str() const {
	stringstream ss;
	ss << fixed << setprecision(2) << value_;
	return Property::string_type(ss.str());
}