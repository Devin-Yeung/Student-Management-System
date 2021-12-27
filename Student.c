#include "Student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void initSchool(School * school){
    school -> head = NULL;
    school -> tail = NULL;
    return;
}





void addStudent(Student * stu, School * school){
    // check if school is empty
    if(school -> head == NULL){
        school -> head = stu;
        school -> tail = stu;
        stu -> pre = NULL;
        stu -> next = NULL;
    }
    else{
        // link previous tail to the new node
        school -> tail -> next = stu;
        // set the next node of the new node
        stu -> next = NULL;
        // set the previous node of current node
        stu -> pre = school -> tail;
        // reset the tail node of the list
        school -> tail = stu;
    }
    return;
}




// Need to test later
void delStudent(Student * stu, School * school){
    if(stu == NULL){
        return;
    }

    // if the deleted stu is the first stu in the list
    if(stu == school -> head){
        // which means there is only one student in the list
        if(school -> head == school -> tail){
            // reset head and tail
            school -> head = NULL;
            school -> tail = NULL;
            free(stu);
            return;
        }
        
        // reset head
        school -> head = stu -> next;
        free(stu);
    }
    // if the deleted stu is the last student in the list
    else if(stu == school -> tail){
        Student * preStu = stu -> pre;
        preStu -> next = NULL;
        school -> tail = preStu;
    }
    // if the deleted stu is NOT the first student or the last student in the list
    else {
        Student * preStu = stu -> pre;
        Student * nextStu = stu -> next;
        preStu -> next = nextStu;
        free(stu);
    }
}





void showStudent(School * school){

    if(school -> head == NULL){
        printf("No Data!\n");
        return;
    }

    // print the head of the table
    printf("|%-15s\t%-10s%-14s\t%-14s%-14s%-14s%-20s%-20s%-7s|\n","专业","班级","姓名","高数","英语","语文","学业总成绩","课外表现分","绩点");

    Student * pscan = school -> head;
    // print out all the student information
    while(pscan != NULL){
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
        pscan = pscan -> next;
    }
}