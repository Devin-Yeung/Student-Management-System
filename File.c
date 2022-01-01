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





void backup(void){
    char c[4096];
    //create and write to file
    FILE * source = fopen("stu.txt","r");
    FILE * backup = fopen("backup.txt","w");   

    while (!feof(source)) {
        size_t bytes = fread(c,1,sizeof(c),source);
        if (bytes) {
            fwrite(c,1,bytes,backup);
        }
    }
    //close streams
    fclose(source);
    fclose(backup);
    return;
}
