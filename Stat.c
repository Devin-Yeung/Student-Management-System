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
        printf("List is empty");
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
    printf("GPA avg is %.2f\n",gpaAvg);
    printf("GPA max is %.2f\n",gpaMax);
    printf("GPA min is %.2f\n",gpaMin);
    
    printf("Inclass avg is %.2f\n",inclassAvg);
    printf("Inclass max is %.2f\n",inclassMax);
    printf("Inclass min is %.2f\n",inclassMin);

    printf("Outclass avg is %.2f\n",outclassAvg);
    printf("Outclass max is %.2f\n",outclassMax);
    printf("Outclass min is %.2f\n",outclassMin);

}