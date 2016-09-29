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
    if ( head->next == nullptr ) return head;

    // Divide into left and right sublists
    split( head, left, right);

    // Conquer left and right sublists
    left = msort( left, compare );
    right = msort( right, compare );

    // Combine left and right sublists
    head = merge(left, right, compare);

    return head;
}

void split(Node *head, Node *&left, Node *&right) {
    Node *slow_ptr = head,*fast_ptr = head;

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

    //initalize variaables
    Node *leftComp = left, *rightComp = right, *sorted = nullptr, *newHead = nullptr;

    //set head of list
    if (compare(leftComp, rightComp)) {
            newHead = leftComp;
            //iterate list value is taken from
            leftComp = leftComp->next;
        }
        else {
            newHead = rightComp;
            //iterate list value is taken from
            rightComp = rightComp->next;
        }


    //march through both lists, compare and fill new sorted list
    while(leftComp != nullptr && rightComp != nullptr){

        //compare current node in each list
        if (compare(leftComp, rightComp)) {
            //set current value in sorted list
            sorted->next = leftComp;
            //iterated left list past just used value
            leftComp = leftComp->next;
            //iterate sorted list so it doesn't overwrite old value'
            sorted = sorted->next;
        }
        else {
            //set current value in sorted list
            sorted->next = rightComp;
            //iterate list to next value
            rightComp = rightComp->next;
            //iterate sorted list
            sorted = sorted->next;
        }
    }

    //fill in rest of sorted list if one has not reached end yet
    if(leftComp != nullptr) sorted->next = leftComp;
    else if(rightComp != nullptr) sorted->next = rightComp;

    //return new head of new list
    return newHead;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
