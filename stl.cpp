// stl.cpp

#include "lsort.h"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void stl_sort(List &l, bool numeric) {

    //I found this on stack exchange?
    //should copy list contents to vector
    vector<Node> myVec{ begin(l), end(l) };

    sort( myVec.begin(), myVec.end());

    //Put sorted vector back into linked list
    copy( myVec.begin(), myVec.end(), back_inserter( l ) ); //not sure if real
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
