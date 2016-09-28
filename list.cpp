// list.cpp

#include "lsort.h"

#include <memory>

List::List() {

	head = nullptr;
	length = 0;
}

List::~List() {

	Node *next = nullptr;

	for( Node *curr = head; curr != nullptr; curr = next ) {
		next = curr->next;
		delete curr;
	}
	
}

void List::push_front(const std::string &s) {
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
