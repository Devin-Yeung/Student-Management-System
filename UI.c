#include "Student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void addStudentUI(School * school){
    // create a new student
    Student * pstu = malloc(sizeof(Student));
    memset(pstu,0,sizeof(Student));
    pstu -> next = NULL;
    // get year
    int year;
    printf("请输入入学年份:\n");
    scanf("%d",&year);

    


    addStudent(pstu,school);
    return;
}




