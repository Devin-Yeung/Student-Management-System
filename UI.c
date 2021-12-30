#include "Student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void addStudentUI(School * school){
    // create a new student
    Student * pstu = malloc(sizeof(Student));
    memset(pstu,0,sizeof(Student));

    // get year
    int year;
    printf("请输入入学年份:\n");
    scanf("%d",&year);

    addStudent(pstu,school);
    return;
}





void filterByClassUI(FilterList * filterList){
    int class;
    printf("请输入班级:");
    fflush(stdin);
    scanf("%d",&class);
    filterByClass(class,filterList);
    return;
}





void filterByYearUI(FilterList * filterList){
    int year;
    printf("请输入年级或入学年份:");
    fflush(stdin);
    scanf("%d",&year);
    filterByYear(year,filterList);
    return;
}





void filterByNameUI(FilterList * filterList){
    char name[NAMELEN];
    printf("请输入学生名称:");
    fflush(stdin);
    scanf("%s",name);
    filterByName(name,filterList);
    return;
}





void filterByMajorUI(FilterList * filterList){
    char major[MAJORLEN];
    printf("请输入专业名称:");
    fflush(stdin);
    scanf("%s",major);
    filterByMajor(major,filterList);
    return;
}





void multiFilterUI(School * school){
    FilterList filterList;
    initFilter(school,&filterList);
    while(1){
        printf("*==================================*\n");
        printf("*      1) Search by Class          *\n");
        printf("*      2) Search by Name           *\n");
        printf("*      3) Search by Year           *\n");
        printf("*      4) Serach by Major          *\n");
        printf("*      5) Search by Score          *\n");
        printf("*      6) Reset Filter             *\n");
        printf("*      7) Delete                   *\n");
        printf("*      8) Keep                     *\n");
        printf("*      9) Quit                     *\n");
        printf("*==================================*\n");
        printf("Please enter the choice number to select the operation:");
        // clean stdin
        fflush(stdin);
        int choice = 0;
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                    filterByClassUI(&filterList);
                    showFilter(&filterList);
                    break;
            case 2:
                    filterByNameUI(&filterList);
                    showFilter(&filterList);
                    break;
            case 3:
                    filterByYearUI(&filterList);
                    showFilter(&filterList);
                    break;
            case 4:
                    filterByMajorUI(&filterList);
                    showFilter(&filterList);
                    break;
            case 5:
                    break;
            case 6:
                    destoryFilter(&filterList);
                    initFilter(school,&filterList);
                    break;
            case 7:
                    break;
            case 8:
                    break;
            case 9:
                    return;
                    break;
            default:
                    break;

        }
    }
    destoryFilter(&filterList);
    return;
}