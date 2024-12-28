#pragma once
#include "Integer.hpp"
#include <cstdlib>
#include <cstddef>
#include <map>

class Node {
	struct PropKey {
		Property::pointer_type prop;
		Property::string_type label;
		PropKey(Property::pointer_type prop, Property::string_type label) : label(label), prop(prop) {}
	};

	static Integer::value_type identity;
public:
	Integer::value_type id;
	DEF_PTR(Node)

	// Getters and setters for properties, ** All nodes have a date property for when they were created **
	Property::pointer_type get(Property::string_type label) { return props[label]; }
	void set(const PropKey& propKey) { props[propKey.label] = propKey.prop; }
	[[nodiscard]] Property::string_type str() const;

	// Auto incrementity identity for id if one isn't specified
	Node(Integer::value_type id = ++identity) : id(id) {}

private:
	std::map<Property::string_type, Property::pointer_type> props;
};

inline std::ostream& operator << (std::ostream& os, Node const& node) {
	return os << node.str();
}