// list.cpp

#include "lsort.h"

#include <memory>

List::List() {

	head = nullptr;
	size = 0;
}

List::~List() {

	Node *next = nullptr;

	for( Node *curr = head; curr != nullptr; curr = next ) {
		next = curr->next;
		delete curr;
	}

}

void List::push_front(const std::string &s) {

	if( head == nullptr ) {
		head = new Node{s, std::stoi(s), nullptr};
	} else {
		Node *temp = head;
		head = new Node{s, std::stoi(s), temp};
	}
	size++;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
