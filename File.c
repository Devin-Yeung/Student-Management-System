#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Student.h"
#include "Login.h"




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
    
    fclose(fp);
    return;
}





void writeFile (School * school){

    FILE * fp = fopen("stu.txt","w");
    if(fp == NULL){
        printf("无法打开文件!");
        return;
    }
    fflush(fp);

        // check if list is empty
    if(school -> head == NULL){
        return;
    }
    Student * stu = school -> head;
    // walk through the stu list
    while(stu != NULL){


        fprintf(fp,"%s %s %d %d %.2f %.2f %.2f %.2f %.2f %.2f\n",
                                                                        stu -> major,
                                                                        stu -> name,
                                                                        stu -> year,
                                                                        stu -> class,
                                                                        stu -> math,
                                                                        stu -> english,
                                                                        stu -> chinese,
                                                                        stu -> inclass,
                                                                        stu -> outclass,
                                                                        stu -> gpa);
        // advance pointer
        stu = stu -> next;
    }

    fclose(fp);
    return;
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





void readUsr (UsrList * usrList){
    FILE * fp = fopen("passwd.txt","r");
    if(fp == NULL){
        printf("无法打开文件!");
        return;
    }
    

    while(1){
        Usr * usr = (Usr*)malloc(sizeof(Usr));
        memset(usr,0,sizeof(Usr));
        int count = 0;
        count  = fscanf(fp,"%s%d%s%d%d%s%s",
        usr -> usrName,
        &usr -> usrGroup,
        usr -> major,
        &usr -> class,
        &usr -> year,
        usr -> hashedPasswd,
        usr -> digest);
        
        // if counter < 7 means EOF or wrong file input
        if(count != 7){
            break;
        }
        addUsr(usr,usrList);
    }

    fclose(fp);
    return;
}





void writeUsr (UsrList * usrList){

    if (usrList -> head == NULL){
        return;
    }


    FILE * fp = fopen("passwd.txt","w");
    if(fp == NULL){
        printf("无法打开文件!");
        return;
    }
    fflush(fp);

    Usr * pusr = usrList -> head;
    
    while(pusr != NULL){
        fprintf(fp,"%s %d %s %d %d %s %s\n",
        pusr -> usrName,
        pusr -> usrGroup,
        pusr -> major,
        pusr -> class,
        pusr -> year,
        pusr -> hashedPasswd,
        pusr -> digest);
        // advance pointer
        pusr = pusr -> next;
    }
    
    fclose(fp);
    return;
}