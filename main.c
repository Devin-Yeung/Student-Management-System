#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Student.h"
#include "Login.h"


int main(void){


    // init usr list
    UsrList usrList;
    initUsr(&usrList);
    // file io
    readUsr(&usrList);
    // create a new usr
    Usr usr;
    memset(&usr,0,sizeof(usr));
    // check if login successfully
    if(usrLoginUI(&usr,&usrList) == 0){
        return 0;
    }


    // init the stu list from the file
    School school;
    initSchool(&school);
    readFile(&school);

    // init filter according to your usr group
    FilterList filterList;
    initFilter(&school,&filterList);
    _Bool willQuit = 0;
    while(willQuit == 0){
        printf("*===========================================*\n");
        printf("*        1) 根据班级查询                     \n");
        printf("*        2) 根据姓名查询                     \n");
        printf("*        3) 根据入学年份查询                  \n");
        printf("*        4) 根据专业查询                     \n");
        printf("*        5) 根据分数查询                     \n");
        printf("*        6) 重置查询条件                     \n");
        printf("*        7) 删除当前查询到的学生               \n");
        printf("*        8) 仅保留当前查询到的学生             \n");
        printf("*        9) 统计当前查询到的学生的分数          \n");
        printf("*        10) 对当前查询到的学生的GPA排序        \n");
        printf("*        11) 按区间统计当前查询到的学生的分数    \n");
        printf("*        12) 添加学生                        \n");        
        printf("*        13) 修改当前学生信息                  \n");
        printf("*        14) 退出                            \n");
        printf("*==========================================*\n");
        printf("请根据您的需求选择功能:");
        // clean stdin
        fflush(stdin);
        int choice = 0;
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                    filterByClassUI(&filterList);
                    showFilter(&school,&filterList);
                    break;
            case 2:
                    filterByNameUI(&filterList);
                    showFilter(&school,&filterList);
                    break;
            case 3:
                    filterByYearUI(&filterList);
                    showFilter(&school,&filterList);
                    break;
            case 4:
                    filterByMajorUI(&filterList);
                    showFilter(&school,&filterList);
                    break;
            case 5:
                    filterByScoreUI(&filterList);
                    showFilter(&school,&filterList);
                    break;
            case 6:
                    destoryFilter(&filterList);
                    initFilter(&school,&filterList);
                    break;
            case 7:
                    delByFilter(&school,&filterList);
                    break;
            case 8:
                    keepByFilter(&school,&filterList);
                    break;
            case 9:
                    showStat(&filterList);
                    break;
            case 10:
                    sortFilter(&filterList);
                    showFilter(&school,&filterList);
                    break;
            case 11:
                    StatGpaByIntervalUI(&filterList);
                    break;
            case 12:
                    addStudentUI(&school);
                    // reset the filter after adding a new stu
                    initFilter(&school,&filterList);
                    break;
            case 13:
                    modifyStudentUI(&school,&filterList);
                    break;
            case 14:
                    destoryFilter(&filterList);
                    willQuit = 1;
                    break;
            default:
                    printf("您输入了错误的选择!\n");
                    printf("请重新选择!\n");
                    break;
        }
    }
    destoryFilter(&filterList);

    // multiFilterUI(&school);

    // file io
    writeFile(&school);
    writeUsr(&usrList);
    backup();
    return 0;
}