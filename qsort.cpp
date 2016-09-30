// qsort.cpp
// Kyle Williams
// Thomas Franceschi

#include "lsort.h"

#include <vector>
#include <cstdlib>

void qsort_sort(List &l, bool numeric) {

    std::vector<Node*> listVec;

    while(l.head != nullptr){
        listVec.push_back(l.head);
        l.head = l.head->next;
    }

    l.head = nullptr;

    if(numeric){
        std::qsort(&listVec[0], l.size, sizeof(Node *), void_number_compare);
    } else {
        std::qsort(&listVec[0], l.size, sizeof(Node *), void_string_compare);
    }

    for(int i = listVec.size() - 1; i >= 0; i--){
        l.push_front(listVec[i]->string);
    }

}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
