#include "Student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void initFilter (School * school, FilterList * filterList){
    Student * pstu = school -> head;
    Filter * pfilter = filterList -> head;

    if(pstu == NULL){
        return;
    }
    
    while(pstu != NULL){
        pfilter = (Filter*)malloc(sizeof(Filter));
        pfilter -> stu = pstu;
        addFilter(pfilter, filterList);
        pstu = pstu -> next;
    }

}



 

void addFilter(Filter * filter, FilterList * filterList){
    // check if FilterList is empty
    if(filterList -> head == NULL){
        filterList -> head = filter;
        filterList -> tail = filter;
        filter -> pre = NULL;
        filter -> next = NULL;
    }
    else{
        // link previous tail to the new node
        filterList -> tail -> next = filter;
        // set the next node of the new node
        filter -> next = NULL;
        // set the previous node of current node
        filter -> pre = filterList -> tail;
        // reset the tail node of the list
        filterList -> tail = filter;
    }
    return;
}





// Need to test later
void delFilter(Filter * filter, FilterList * filterList){
    if(filterList == NULL){
        return;
    }

    // if the deleted filter is the first filter in the list
    if(filter == filterList -> head){
        // which means there is only one filter in the list
        if(filterList -> head == filterList -> tail){
            // reset head and tail
            filterList -> head = NULL;
            filterList -> tail = NULL;
            free(filterList);
            return;
        }
        
        // reset head
        filterList -> head = filter -> next;
        free(filterList);
    }
    // if the deleted filter is the last Filter in the list
    else if(filter == filterList -> tail){
        Filter * prefilter = filter -> pre;
        prefilter -> next = NULL;
        filterList -> tail = prefilter;
    }
    // if the deleted filter is NOT the first filter or the last filter in the list
    else {
        Filter * prefilter = filter -> pre;
        Filter * nextfilter = filter -> next;
        prefilter -> next = nextfilter;
        free(filter);
    }
}