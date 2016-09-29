// merge.cpp
//Thomas Franceschi
//Kyle Williams

//NOTE TO SELF: Initialize ALL pointers

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
    if ( head->next == nullptr ) return head;

    // Divide into left and right sublists
    split( head, left, right);

    // Conquer left and right sublists (recurse)
    left = msort( left, compare );
    right = msort( right, compare );

    // Combine left and right sublists
    head = merge(left, right, compare);

    return head;
}

void split(Node *head, Node *&left, Node *&right) {
    //intialize variables
    Node *slow_ptr = head, *fast_ptr = head;

    //find middle of list
    while(!slow_ptr && !fast_ptr && fast_ptr->next != NULL) {
        slow_ptr = slow_ptr->next;  //move slow pointer 1 node each iteration
        fast_ptr = fast_ptr->next->next;  //move fast pointer 2 nodes each iteration
    }

    //split list
    left = head; //set head of left list
    right = slow_ptr->next; //set head of right list
    slow_ptr->next = nullptr; //set end of left list
}

Node *merge(Node *left, Node *right, CompareFunction compare) {

    //initalize variables
    Node *curr = nullptr, *newHead = nullptr;

    //set head of list
    if (compare(left, right)) {
            newHead = left;
            //iterate list value is taken from
            left = left->next;
        }
        else {
            newHead = right;
            //iterate list value is taken from
            right = right->next;
        }

        //set head to curr (I got so many errors because I forgot to do this forever)
        curr = newHead;

    //march through both lists, compare and fill new curr list
    while(left != nullptr && right != nullptr){

        //compare current node in each list
        if (compare(left, right)) {
            //set current value in curr list
            curr->next = left;
            //iterated left list past just used value
            left = left->next;
            //iterate curr list so it doesn't overwrite old value'
            curr = curr->next;
        }
        else {
            //set current value in curr list
            curr->next = right;
            //iterate list to next value
            right = right->next;
            //iterate curr list
            curr = curr->next;
        }
    }

    //fill in rest of curr list if one has not reached end yet
    if(left != nullptr) curr->next = left;
    else if(right != nullptr) curr->next = right;

    //return new head of new list
    return newHead;
}
