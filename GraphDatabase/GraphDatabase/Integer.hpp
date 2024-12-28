#pragma once
#include "Numeric.hpp"
class Integer : public Numeric {
public:
	using value_type = long long;
	DEF_PTR(Integer)

	[[nodiscard]] string_type str() const override;

	Integer(value_type value = 0) : value_(value) {}
private:
	value_type value_;
};