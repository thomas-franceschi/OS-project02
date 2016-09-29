// qsort.cpp

#include "lsort.h"

#include <cstdlib>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

void qsort_sort(List &l, bool numeric) {
    
    /*
    //Dump contents of linked list into vector
    Node* node = l.head;
    vector<Node*> myVec;
    
    while (node != nullptr ) {
        myVec.push_back(node);
        node = node->next;
    }*/

    //I found this on stack exchange?
    //should copy list contents to vector
    vector<Node> myVec{ begin(l), end(l) };

    //sort vector
    qsort( myVec.begin(), myVec.size(),sizeof(int), compare_thing_goes_here );

    //Put sorted vector back into linked list
    copy( myVec.begin(), myVec.end(), back_inserter( l ) ); //not sure if real
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
