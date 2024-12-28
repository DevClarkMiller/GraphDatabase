#pragma once
#include <cstdlib>
#include <cstddef>
#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

#define DEF_PTR(class_) using pointer_type = std::shared_ptr<class_>;

class Property {
public:
	using string_type = std::string;
	DEF_PTR(Property)
	virtual ~Property() = default;
	constexpr Property() = default;
	[[nodiscard]] virtual string_type str() const;
};

/*! Convert to subclass type. */
template <typename CONVERTED_TYPE>
[[nodiscard]] inline typename CONVERTED_TYPE::pointer_type convert(Property::pointer_type const& tkn) {
	return std::dynamic_pointer_cast<CONVERTED_TYPE>(tkn);
}

/*! Returns the value of a property pointer */
template <typename DATA_TYPE, typename PROPERTY_PTR>
DATA_TYPE& get_value(PROPERTY_PTR prop_ptr) {
	return *prop_ptr;
}

template <typename DATA_TYPE, typename PROPERTY_PTR>
bool is(PROPERTY_PTR prop_ptr) {
	return std::dynamic_pointer_cast<DATA_TYPE>(prop_ptr);
}

/*! Make a new smart-pointer managed property object. */
template <typename T> [[nodiscard]] inline
Property::pointer_type make() { return Property::pointer_type(new T); }

/*! Make a new smart-pointer managed property object with constructor parameter. */
template <typename T, typename U> [[nodiscard]] inline
Property::pointer_type make(U const& param) { return Property::pointer_type(new T(param)); }

/*! stream operators */
inline std::ostream& operator << (std::ostream& os, Property const& prop) {
	return os << prop.str();
}

inline std::ostream& operator << (std::ostream& os, Property::pointer_type const& prop) {
	return os << prop->str();
}