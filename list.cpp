// list.cpp

#include "lsort.h"

#include <memory>
#include <string>

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
<<<<<<< HEAD
		head = new Node{s, std::stoi(s), nullptr};
	} 
	else {
		Node *temp = head;
		head = new Node{s, std::stoi(s), temp->next};
=======
		if(!std::stoi(s)){
			head = new Node{s, 0, nullptr};
		} else {
			head = new Node{s, std::stoi(s), nullptr};
		}
	} else {
		Node *temp = head;
		
		if(!std::stoi(s)){
			head = new Node{s, 0, temp};
		} else {
			head = new Node{s, std::stoi(s), temp};
		}
>>>>>>> 56d94ffafb839f748951050ef5336316a7ccd317
	}
	size++;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
