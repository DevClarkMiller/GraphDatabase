#pragma once
#include "Relationship.hpp"
using namespace std;

Property::string_type Relationship::str() const {
	stringstream ss;
	if (!head || !tail)
		ss << "No nodes defined";
	else
		ss << head->id << "->" << tail->id;
	return Property::string_type(ss.str());
}

Property::string_type WeightedRelationship::str() const {
	stringstream ss;
	if (!head || !tail)
		ss << "No nodes defined";
	else
		ss << head->id << "->" << tail->id << ", weight(" << weight << ")";
	return Property::string_type(ss.str());
}