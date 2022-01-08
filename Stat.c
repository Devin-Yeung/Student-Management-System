#include "Student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void showStat(FilterList * filterList){
    float gpaAvg = 0;
    float gpaMax = 0;
    float gpaMin = 32767;

    float inclassAvg = 0;
    float inclassMax = 0;
    float inclassMin = 32767;

    float outclassAvg = 0;
    float outclassMax = 0;
    float outclassMin = 32767;

    int counter = 0;


    Filter * pfilter = filterList -> head;
    if(pfilter == NULL){
        printf("列表为空!无法为您统计数据!\n");
        return;
    }
    
    while(pfilter != NULL){
        Student * pstu = pfilter -> stu;

        gpaAvg += pstu -> gpa;
        inclassAvg += pstu -> inclass;
        outclassAvg += pstu -> outclass;
    

        if(pstu -> gpa > gpaMax){
            gpaMax = pstu -> gpa;
        }
        else if(pstu -> gpa < gpaMin){
            gpaMin = pstu -> gpa;
        }
        else;

        if(pstu -> inclass > inclassMax){
            inclassMax = pstu -> inclass;
        }
        else if(pstu -> inclass < inclassMin){
            inclassMin = pstu -> inclass;
        }
        else;


        if(pstu -> outclass > outclassMax){
            outclassMax = pstu -> outclass;
        }
        else if(pstu -> outclass < outclassMin){
            outclassMin = pstu -> outclass;
        }
        else;

        pfilter = pfilter -> next;
        counter++;
    }

    gpaAvg /= counter;
    inclassAvg /= counter;
    outclassAvg /= counter;


    // output
    printf("平均 GPA 为 %.2f\n",gpaAvg);
    printf("最高 GPA 为 %.2f\n",gpaMax);
    printf("最低 GPA 为 %.2f\n",gpaMin);
    
    printf("平均课内总成绩为 %.2f\n",inclassAvg);
    printf("最高课内总成绩为 %.2f\n",inclassMax);
    printf("最低课内总成绩为 %.2f\n",inclassMin);

    printf("平均课外总成绩为 %.2f\n",outclassAvg);
    printf("最高课外总成绩为 %.2f\n",outclassMax);
    printf("最高课外总成绩为 %.2f\n",outclassMin);

}





void statGpaByInterval(int interval, FilterList * filterList){

    // check if list is empty
    if(filterList -> head == NULL){
        printf("列表为空!无法为您统计数据!\n");
        return;
    }


    // init the min score and max score
    int max = 240;
    int min = 0;

    // statList store how many students are there in the specific interval
    int * statList = (int *)malloc(sizeof(int[max / interval + 1]));
    memset(statList,0,sizeof(*statList));
    int counter = 0;
    for(int i = min; i < max; i += interval, counter++){
        // walk through the linklist
        Filter * pfilter = filterList -> head;
        while(pfilter != NULL){
            float gpa = pfilter -> stu -> gpa;
            if(i < gpa && gpa <= i + interval){
                statList[counter]++;
            }
            // advance pointer
            pfilter = pfilter -> next;
        }
    }

    // print out the stat information
    for(int i = 0; i < counter; i++){
        int lower = min + i * interval;
        int upper = (min + (i + 1) * interval < max) ? (min + (i + 1) * interval) : max;
        printf("%d分 ~ %d分 共 %d 人\n",lower, upper, statList[i]);
    }

    free(statList);
    return;
}