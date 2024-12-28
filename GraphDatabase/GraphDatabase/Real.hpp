#pragma once
#include "Numeric.hpp"
class Real : public Numeric {
public:
	using value_type = long double;
	DEF_PTR(Real)

	[[nodiscard]] string_type str() const override;

	Real(value_type value = 0.0) : value_(value) {}
private:
	value_type value_;
};