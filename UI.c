#include "Student.h"
#include "Login.h"
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






void modifyStudentUI(School * school, FilterList * filterList){

    if(filterList -> head != filterList -> tail){
        printf("您正在尝试同时修改多个学生的信息，请指定具体的学生再进行修改\n");
        return;
    }

    while(1){

        // create a new student
        Student * pstu = filterList -> head -> stu;
        showFilter(school,filterList);
        printf("*==================================*\n");
        printf("*           1) 修改姓名               \n");
        printf("*           2) 修改专业               \n");
        printf("*           3) 修改入学年份            \n");
        printf("*           4) 修改班级               \n");
        printf("*           5) 修改数学成绩            \n");
        printf("*           6) 修改英语成绩            \n");
        printf("*           7) 修改语文成绩            \n");
        printf("*           8) 修改课外成绩           \n");
        printf("*           9) 退出修改               \n");
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
                    getYearUI(pstu);
                    break;
            case 4:
                    getClassUI(pstu);
                    break;
            case 5:
                    getScoreUI(MATH,pstu);
                    break;
            case 6:
                    getScoreUI(ENGLISH,pstu);
                    break;
            case 7:
                    getScoreUI(CHINESE,pstu);
                    break;
            case 8:
                    getScoreUI(OUTCLASS,pstu);
                    break;
            case 9:
                    return;
                    break;
            default: 
                    printf("您输入了错误的选择!\n");
                    printf("请重新选择!\n");
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
        printf("*==========================================*\n");
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
        printf("*        12) 修改当前学生信息                  \n");
        printf("*        13) 退出查询                         \n");
        printf("*=========================================*\n");
        printf("请根据您的需求选择功能:");
        // clean stdin
        fflush(stdin);
        int choice = 0;
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                    filterByClassUI(&filterList);
                    showFilter(school,&filterList);
                    break;
            case 2:
                    filterByNameUI(&filterList);
                    showFilter(school,&filterList);
                    break;
            case 3:
                    filterByYearUI(&filterList);
                    showFilter(school,&filterList);
                    break;
            case 4:
                    filterByMajorUI(&filterList);
                    showFilter(school,&filterList);
                    break;
            case 5:
                    break;
            case 6:
                    destoryFilter(&filterList);
                    initFilter(school,&filterList);
                    break;
            case 7:
                    delByFilter(school,&filterList);
                    break;
            case 8:
                    keepByFilter(school,&filterList);
                    break;
            case 9:
                    showStat(&filterList);
                    break;
            case 10:
                    sortFilter(&filterList);
                    showFilter(school,&filterList);
                    break;
            case 11:
                    StatGpaByIntervalUI(&filterList);
                    break;
            case 12:
                    modifyStudentUI(school,&filterList);
                    break;
            case 13:
                    destoryFilter(&filterList);
                    return;
                    break;
            default:
                    printf("您输入了错误的选择!\n");
                    printf("请重新选择!\n");
                    break;
        }
    }
    destoryFilter(&filterList);
    return;
}





void StatGpaByIntervalUI (FilterList * filterList){
    char input[256];
    int interval = 0;
    printf("请输入区间大小（粒度）");
    fflush(stdin);
    fgets(input,256,stdin);

    if((interval = atoi(input)) == 0){
        interval = 20;
        printf("检测到您没有输入,使用默认区间大小20\n");
    }
    statGpaByInterval(interval,filterList);
    return;
}





// FIXME: need to check usr
void addUsrUI(UsrList * usrList){
    Usr * usr = (Usr*)malloc(sizeof(Usr));
    char passwd[PASSWDLEN];
    memset(passwd,0,sizeof(char[PASSWDLEN]));    


    // get usr name
    printf("请输入用户名（姓名）:");
    fflush(stdin);
    while(scanf("%s",usr -> usrName) != 1){
        fflush(stdin);
        printf("输入错误,请重新输入:\n");
    }

    printf("请输入用户密码:");
    fflush(stdin);
    while(scanf("%[^\n]%*c",passwd) != 1){
        fflush(stdin);
        printf("非法输入,请重新输入:\n");
    }

    // get major
    printf("请输入所在专业:");
    fflush(stdin);
    while(scanf("%s",usr -> major) != 1){
        fflush(stdin);
        printf("输入错误,请重新输入:\n");
    }

    // get class
    printf("请输入所在班级:");
    fflush(stdin);
    while(scanf("%d",&usr -> class) != 1){
        fflush(stdin);
        printf("输入错误,请重新输入:\n");
    }

    // get year
    printf("请输入入学年份:");
    fflush(stdin);
    while( scanf("%d",&usr -> year) != 1){
        fflush(stdin);
        printf("输入错误,请重新输入:\n");
    }

    // crypto the passwd
    cal_string_hash(passwd, usr -> hashedPasswd);

    // cal the digest
    cal_digest(usr, usr -> digest);

    // testing 
    printf("%s\n%s\n%s\n",passwd, usr -> hashedPasswd, usr -> digest);

    addUsr(usr,usrList);
    return;
}