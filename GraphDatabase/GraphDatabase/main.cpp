#include <iostream>
#include "Types.hpp"
#include "Node.hpp"
#include "Relationship.hpp"
using namespace std;

int main() {
	Node::pointer_type node = shared_ptr<Node>(new Node);
	node->set({make<Str>("Clark"), "Name"});
	node->set({make<Integer>(20), "Age"});
	node->set({make<Money>(10000.51), "Bank Balance"});

	Node::pointer_type node2 = shared_ptr<Node>(new Node);
	node2->set({ make<Str>("Peter"), "Name" });
	cout << *node << endl << *node2 << endl;

	// Relationship with no nodes attached
	Relationship rel("Friend");
	cout << rel << endl;

	// Relationship with nodes on both end
	Relationship rel2("Friend", node, node2);
	cout << rel2 << endl;
}