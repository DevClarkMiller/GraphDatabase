#pragma once
#include "Real.hpp"
class Money : public Real {
public:
	using value_type = long double;
	DEF_PTR(Money)

	[[nodiscard]] string_type str() const override;

	Money(value_type value = 0.0) : value_(value) {}
private:
	value_type value_;
};