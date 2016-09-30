// node.cpp
// Kyle Williams
// Thomas Franceschi

#include "lsort.h"

#include <iostream>
#include <cstring>

bool node_number_compare(const Node *a, const Node *b) {
	return a->number < b->number;
}

bool node_string_compare(const Node *a, const Node *b) {
	return a->string < b->string;
}

int void_number_compare(const void *a, const void *b) {

	Node **numA = (Node **)a;
	Node **numB = (Node **)b;

	return (*numA)->number - (*numB)->number;
}

int void_string_compare(const void *a, const void *b) {

	Node *stringA = *(Node **)a;
	Node *stringB = *(Node **)b;

	return std::strcmp(stringA->string.c_str(), stringB->string.c_str());

}

void dump_node(Node *n) {

	while(n != nullptr){
		std::cout << n->number << std::endl;
		n = n->next; 
	}

}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
