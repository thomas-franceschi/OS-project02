// stl.cpp
// Kyle Williams
// Thomas Franceschi

#include "lsort.h"

#include <vector>
#include <algorithm>

void stl_sort(List &l, bool numeric) {

    std::vector<Node*> listVec;

    while(l.head != nullptr){
    	listVec.push_back(l.head);
    	l.head = l.head->next;
    }

    if(numeric){
    	std::sort(listVec.begin(), listVec.end(), node_number_compare);
    } else {
    	std::sort(listVec.begin(), listVec.end(), node_string_compare);
    }

    l.head = listVec[0];
    for(int i = 0; i < listVec.size(); i++){
        listVec[i]->next = listVec[i+1];
    }

}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
