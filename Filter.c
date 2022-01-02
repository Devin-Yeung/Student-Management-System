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





void reinitFilter(FilterList * filterList){
    Filter * pfilter = filterList -> head;

    if(pfilter == NULL){
        filterList -> head = NULL;
        filterList -> head = NULL;
        return;
    }

    // reset head
    filterList -> head = pfilter;
    // reset the pre of first node
    pfilter -> pre = NULL;

    Filter * tmp = NULL;
    while(pfilter != NULL){
        if(pfilter -> next == NULL){
            // reset tail
            filterList -> tail = pfilter;
        }

        // reinit the pre node
        pfilter -> pre = tmp;
        // reset pre
        tmp = pfilter;
        pfilter = pfilter -> next;
    }
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




 
Filter * mergeFilter(Filter * f1, Filter * f2){

    //  check if list is empty
     if(f1 == NULL){
         return f2;
     }
     
     if(f2 == NULL){
         return f1;
     }

    if(f1 -> stu -> gpa > f2 -> stu -> gpa){
        f1 -> next = mergeFilter(f1 -> next, f2);
        return f1;
    }
    else{
        f2 -> next = mergeFilter(f2 -> next, f1);
        return f2;
    }

 }



Filter * toSortFilter(Filter * head, Filter * tail){
    // check if list is empty
    if(head == NULL){
        return head;
    }

    // if there is only one node
    if(head == tail){
        return head;
    }
    
    // if there only two nodes in the list(stop)
    if(head -> next == tail){
        head -> next = NULL;
        tail -> next = NULL;
        return mergeFilter(head,tail);
    }

    // fast,slow pointer to find the mid point 
    Filter * fast = head;
    Filter * slow = head;
    while(fast != tail){
        // advance pointer
        fast = fast -> next;
        if(fast != tail){
            slow = slow -> next;
            // advance fast pointer twice
            fast = fast -> next;
        }
    }
    Filter * tmp = slow -> next;
    slow -> next = NULL;
    return mergeFilter(toSortFilter(head, slow),toSortFilter(tmp, tail));
}





void sortFilter(FilterList * filterList){
    Filter * head = filterList -> head;
    Filter * tail = filterList -> tail;
    filterList -> head = toSortFilter(head,tail);
    reinitFilter(filterList);
}


void showFilter(FilterList * filterList){

    if(filterList -> head == NULL){
        printf("Nothing match\n");
        return;
    }

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
        if (strcmp(name,pstu -> name)!= 0){
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





void delByFilter (FilterList * filterList, School * school){

    if(filterList -> head == NULL){
        printf("List is empty!\n");
        return;
    }

    Filter * pfilter = filterList -> head;
    while(pfilter != NULL){
        delStudent(pfilter -> stu, school);
        pfilter = pfilter -> next;
    }
    return;
}