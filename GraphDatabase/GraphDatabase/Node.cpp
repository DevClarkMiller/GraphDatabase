#include "Node.hpp"
#include <algorithm>
using namespace std;

Integer::value_type Node::identity = 0;

Property::string_type Node::str() const {
	stringstream ss;
	ss << "ID: " << id << endl;
	if (props.size() == 0) {
		ss << "No Properties";
	}
	else {
		for (const auto& [label, prop] : props) 
			ss << label << ": " << prop << endl;
	}
	return Property::string_type(ss.str());
}