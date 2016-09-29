// merge.cpp

#include "lsort.h"

#include <iostream>

// Prototypes

Node *msort(Node *head, CompareFunction compare);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, CompareFunction compare);

// Implementations

void merge_sort(List &l, bool numeric) {
    //sort either numeric or string
    if (numeric) l.head = msort( l.head, node_number_compare );
    else l.head = msort( l.head, node_string_compare );
}

Node *msort(Node *head, CompareFunction compare) {
    Node *left = nullptr, *right = nullptr; //initialize left and right list pointers
    
    // Handle base case
    if (head->next == nullptr) return head;

    // Divide into left and right sublists
    split( head, left, right);

    // Conquer left and right sublists
    left = msort( left, compare);
    right = msort(right, compare);

    // Combine left and right sublists
    head = merge(left, right, compare);
}

void split(Node *head, Node *&left, Node *&right) {
    Node *slow_ptr,*fast_ptr;

    //find middle of list
    while(!slow_ptr && !fast_ptr && fast_ptr->next != NULL) {
        slow_ptr = slow_ptr->next;  // moves one node ahead at a time
        fast_ptr = fast_ptr->next->next;  // moves two nodes ahead at a time
    }

    //split list
    left = head; //set head of left list
    right = slow_ptr->next; //set head of right list
    slow_ptr->next = nullptr; //set end of left list
}

Node *merge(Node *left, Node *right, CompareFunction compare) {



}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
