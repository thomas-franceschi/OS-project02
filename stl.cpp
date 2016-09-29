// stl.cpp

#include "lsort.h"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void stl_sort(List &l, bool numeric) {

    vector<Node*> listVec;

    while(l.head != nullptr){
    	listVec.push_back(l.head);
    	l.head = l.head->next;
    }

    if(numeric){
    	std::sort(listVec.begin(), listVec.end(), node_number_compare);
    } else {
    	std::sort(listVec.begin(), listVec.end(), node_string_compare);

    }

    for(int i = listVec.size() - 1; i >= 0; i--){
    	l.push_front(listVec[i]->string);
    }

}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
