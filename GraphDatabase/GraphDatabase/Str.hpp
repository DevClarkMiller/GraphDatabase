#pragma once
#include "Property.hpp"

class Str : public Property {
public:
	using value_type = Property::string_type;
	DEF_PTR(Str)
	[[nodiscard]] string_type str() const override;

	Str(value_type value = "") : value_(value) {}

private:
	value_type value_;
};