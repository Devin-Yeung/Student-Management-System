#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Student.h"




void readFile (School * school){
    FILE * fp = fopen("stu.txt","r");
    if(fp == NULL){
        printf("无法打开文件!");
        return;
    }
    

    while(1){
        Student * stu = (Student*)malloc(sizeof(Student));
        memset(stu,0,sizeof(Student));
        int count;

        count = fscanf(fp,"%s%s%d%d%f%f%f%f%f%f",stu -> major,
                                              stu -> name,
                                              &stu -> year,
                                              &stu -> class,
                                              &stu -> math,
                                              &stu -> english,
                                              &stu -> chinese,
                                              &stu -> inclass,
                                              &stu -> outclass,
                                              &stu -> gpa); 
        
        // if counter <10 means EOF or wrong file input
        if(count != 10){
            break;
        }

        addStudent(stu,school);
    }
}



