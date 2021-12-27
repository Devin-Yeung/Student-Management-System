#include "Student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void initSchool(School * school){
    school -> head = NULL;
    return;
}





void addStudent(Student * stu, School * school){
    // check if school is empty
    if(school -> head == NULL){
        school -> head = stu;
        school -> end = stu;
    }
    else{
        school -> end -> next = stu;
        school -> end = stu;
    }
    return;
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