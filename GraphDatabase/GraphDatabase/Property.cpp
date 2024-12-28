#include "Property.hpp"

[[nodiscard]] Property::string_type Property::str() const {
	return string_type("<") + string_type(typeid(*this).name()).substr(6) + string_type(">");
}