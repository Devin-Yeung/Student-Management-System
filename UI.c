#include "Student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void addStudentUI(School * school){
    // create a new student
    Student * pstu = malloc(sizeof(Student));
    memset(pstu,0,sizeof(Student));

    getNameUI(pstu);
    getMajorUI(pstu);
    getClassUI(pstu);
    getScoreUI(MATH,pstu);
    getScoreUI(ENGLISH,pstu);
    getScoreUI(CHINESE,pstu);
    getScoreUI(OUTCLASS,pstu);

    // calculate the score
    pstu -> inclass = (pstu -> math) + (pstu -> english) + (pstu -> chinese);
    
    pstu -> gpa = 0.7 * (pstu -> inclass) + 0.3 * (pstu -> outclass);

    addStudent(pstu,school);
    return;
}






void modifyStudentUI(FilterList * filterList){

    if(filterList -> head != filterList -> tail){
        printf("您正在尝试同时修改多个同学的信息，请指定具体的同学再进行修改\n");
        return;
    }

    while(1){

        // create a new student
        Student * pstu = filterList -> head -> stu;

        printf("*==================================*\n");
        printf("*      1) Modify Name              *\n");
        printf("*      2) Modify Major             *\n");
        printf("*      3) Modify Class             *\n");
        printf("*      4) Modify Math Score        *\n");
        printf("*      5) Modify English Score     *\n");
        printf("*      6) Modify Chinese Score     *\n");
        printf("*      7) Modify Outclass Score    *\n");
        printf("*      8) Quit                    *\n");
        printf("*==================================*\n");
        printf("Please enter the choice number to select the operation:");
        // clean stdin
        fflush(stdin);
        int choice = 0;
        scanf("%d",&choice);
        switch(choice){
            case 1:
                    getNameUI(pstu);
                    break;
            case 2:
                    getMajorUI(pstu);
                    break;
            case 3:
                    getClassUI(pstu);
                    break;
            case 4:
                    getScoreUI(MATH,pstu);
                    break;
            case 5:
                    getScoreUI(ENGLISH,pstu);
                    break;
            case 6:
                    getScoreUI(CHINESE,pstu);
                    break;
            case 7:
                    getScoreUI(OUTCLASS,pstu);
                    break;
            case 8:
                    return;
                    break;
            default: 
                    printf("Wrong option!\n");
                    return;
                    break;
        }
    }
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





void getNameUI(Student * pstu){
    // get name
    printf("请输入学生姓名:\n");
    fflush(stdin);
    while(scanf("%s",pstu -> name) != 1){
        fflush(stdin);
        printf("输入错误,请重新输入:\n");
    }
    return;
}





void getMajorUI (Student * pstu){
    // get major
    printf("请输入学生专业:\n");
    fflush(stdin);
   
    while( scanf("%s",pstu -> major) != 1){
        fflush(stdin);
        printf("输入错误,请重新输入:\n");
    }
}





void getClassUI (Student * pstu){
    // get class
    printf("请输入学生班级:\n");
    fflush(stdin);
    while(scanf("%d",&pstu -> class) != 1){
        fflush(stdin);
        printf("输入错误,请重新输入:\n");
    }
}





void getYearUI(Student * pstu){
    // get year
    printf("请输入入学年份:\n");
    fflush(stdin);
    while( scanf("%d",&pstu -> year) != 1){
        fflush(stdin);
        printf("输入错误,请重新输入:\n");
    }
}





void getScoreUI(enum Discipline discipline, Student * pstu){
    float * pscore = NULL;
    
    // flag indicate whether user input right data
    int flag = 0;
    while(flag == 0){
        flag = 1;
        switch(discipline){
        case ENGLISH:
            printf("请输入学生英语成绩:\n");
            pscore = &pstu -> english;
            break;
        case CHINESE:
            printf("请输入学生语文成绩:\n");
            pscore = &pstu -> english;
            break;
        case MATH:
            printf("请输入学生数学成绩:\n");
            pscore = &pstu -> math;
            break;
        case OUTCLASS:
            printf("请输入学课外成绩:\n");
            pscore = &pstu -> outclass;
            break;
        default: 
            printf("您选择了错误的学科!\n");
            flag = 0;
        }
    }
    // clear stdin
    fflush(stdin);
    while(scanf("%f",pscore) != 1){
        fflush(stdin);
        printf("输入错误,请重新输入:\n");
    }
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
        printf("*      9) Stat                     *\n");
        printf("*      10) Sort                    *\n");
        printf("*      11) Quit                    *\n");
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
                    showFilter(&filterList);
                    break;
            case 7:
                    delByFilter(&filterList,school);
                    break;
            case 8:
                    break;
            case 9:
                    showStat(&filterList);
                    break;
            case 10:
                    sortFilter(&filterList);
                    showFilter(&filterList);
                    break;
            case 11:
                    return;
                    break;
            default:
                    break;

        }
    }
    destoryFilter(&filterList);
    return;
}