#include "Money.hpp"
using namespace std;

Property::string_type Money::str() const {
	stringstream ss;
	ss << fixed << setprecision(2) << "$" << value_;
	return ss.str();
}