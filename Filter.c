#include "Student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void initFilter (School * school, FilterList * filterList){
    filterList -> head = NULL;
    filterList -> tail = NULL;    
    Student * pstu = school -> head;
    
    while(pstu != NULL){
        Filter * pfilter = (Filter*)malloc(sizeof(Filter));
        pfilter -> stu = pstu;
        addFilter(pfilter, filterList);
        pstu = pstu -> next;
    }
    return;
}





void destoryFilter(FilterList * filterList){
    Filter * pfilter = filterList -> head;
    while(pfilter != NULL){
        Filter * tmp = pfilter -> next;
        free(pfilter);
        // advance pointer
        pfilter = tmp;
    }
    filterList -> head = NULL;
    filterList -> tail = NULL;
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
            free(filter);
            return;
        }
        
        // reset head
        filterList -> head = filter -> next;
        free(filter);
    }
    // if the deleted filter is the last Filter in the list
    else if(filter == filterList -> tail){
        Filter * prefilter = filter -> pre;
        prefilter -> next = NULL;
        filterList -> tail = prefilter;
        free(filter);
    }
    // if the deleted filter is NOT the first filter or the last filter in the list
    else {
        Filter * prefilter = filter -> pre;
        Filter * nextfilter = filter -> next;
        prefilter -> next = nextfilter;
        nextfilter -> pre = prefilter;
        free(filter);
    }
}





void showFilter(FilterList * filterList){

    // print the head of the table
    printf("|%-15s\t%-10s%-14s\t%-14s%-14s%-14s%-20s%-20s%-7s|\n","专业","班级","姓名","高数","英语","语文","学业总成绩","课外表现分","绩点");
    
    Filter * pfilter = filterList -> head;
    // print out all the student information
    while(pfilter != NULL){
        Student * pscan = pfilter -> stu;
        printf("|%-15s\t%-8d%-14s\t%-12.2f%-12.2f%-12.2f%-15.2f%-15.2f%-5.2f|\n",
        pscan -> major,
        pscan -> class,
        pscan -> name,
        pscan -> math,
        pscan -> english,
        pscan -> chinese,
        pscan -> inclass,
        pscan -> outclass,
        pscan -> gpa);
        // advance the pointer
        pfilter = pfilter -> next;
    }
}





void filterByClass(int class, FilterList * filterList){
    Filter * pfilter = filterList -> head;

    while(pfilter != NULL){
        Student * pstu = pfilter -> stu;
        if (pstu -> class != class){
            Filter * tmp = pfilter -> next;
            delFilter(pfilter,filterList);
            pfilter = tmp;
        }
        else{
            pfilter = pfilter -> next;
        }
    }
}





void filterByName(char * name, FilterList * filterList){
    Filter * pfilter = filterList -> head;

    while(pfilter != NULL){
        Student * pstu = pfilter -> stu;
        if (strcmp(name,pstu -> name)){
            Filter * tmp = pfilter -> next;
            delFilter(pfilter,filterList);
            pfilter = tmp;
        }
        else{
            pfilter = pfilter -> next;
        }
    }
}






void filterByYear(int year, FilterList * filterList){
    if(1 <= year && year <= 4){
        // hard code here, can be improved
        year += 2020;
    }
    
    Filter * pfilter = filterList -> head;
    while(pfilter != NULL){
        Student * pstu = pfilter -> stu;
        if (pstu -> year != year){
            Filter * tmp = pfilter -> next;
            delFilter(pfilter,filterList);
            pfilter = tmp;
        }
        else{
            pfilter = pfilter -> next;
        }
    }
}





void filterByMajor(char * major, FilterList * filterList){
    Filter * pfilter = filterList -> head;

    while(pfilter != NULL){
        Student * pstu = pfilter -> stu;
        if (strcmp(major,pstu -> major) != 0){
            Filter * tmp = pfilter -> next;
            delFilter(pfilter,filterList);
            pfilter = tmp;
        }
        else{
            pfilter = pfilter -> next;
        }
    }
}