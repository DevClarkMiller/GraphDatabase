#pragma once
#include "Property.hpp"
#include "Node.hpp"
#include "Real.hpp"
class Relationship {
	Property::string_type label;
public:
	Node::pointer_type head;
	Node::pointer_type tail;

    inline bool incomplete() const { return !head || !tail; }

	Relationship(Property::string_type label) : label(label), head(nullptr), tail(nullptr) {}
	Relationship(Property::string_type label, Node::pointer_type head, Node::pointer_type tail) : 
		label(label),
		head(head),
		tail(tail)
	{}

	[[nodiscard]] virtual Property::string_type str() const;
};

class WeightedRelationship : public Relationship {
	Real::value_type weight;
public:
	WeightedRelationship(Real::value_type weight, Property::string_type label) : weight(weight), Relationship(label) {}
	WeightedRelationship(Real::value_type weight, Property::string_type label, 
		Node::pointer_type head, Node::pointer_type tail) : 
		weight(weight), 
		Relationship(label, head, tail) 
	{}

	[[nodiscard]] Property::string_type str() const override;
};

inline std::ostream& operator << (std::ostream& os, Relationship const& rel) {
	return os << rel.str();
}