// quick.cpp
// Kyle Williams
// Thomas Franceschi

#include "lsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, CompareFunction compare);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, CompareFunction compare);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {

	// sort numerically or by string
	if(numeric){
		l.head = qsort(l.head, node_number_compare);
	} else {
		l.head = qsort(l.head, node_string_compare);
	}

}

Node *qsort(Node *head, CompareFunction compare) {

	if(head == nullptr || head->next == nullptr) return head;

	// node initialization
	Node *pivot = head;
	Node *left  = nullptr;
	Node *right = nullptr;
	head = head->next;

	// divide
	partition(head, pivot, left, right, compare);

	// conquer
	left = qsort(left, compare);
	right = qsort(right, compare);

	// prepend pivot to right list
	pivot->next = right;
	right = pivot;

	// combine
	head = concatenate(left, right);

	return head;

}
 
void partition(Node *head, Node *pivot, Node *&left, Node *&right, CompareFunction compare) {

	Node *curr = head;
	Node *temp;
	while(curr != nullptr){
		temp = curr->next;
		if(compare(curr, pivot)){
			// prepend left
			curr->next = left;
			left = curr;
		} else {
			// prepend rights
			curr->next = right;
			right = curr;
		}

		curr = temp;
	}

}

Node *concatenate(Node *left, Node *right) {

	if(!left) return right;
	if(!right) return left;

	// get to end of left list
	Node *curr = left;
	while(curr->next != nullptr){
		curr = curr->next;
	}

	// point last pointer in left list to right
	curr->next = right;

	return left;

}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
