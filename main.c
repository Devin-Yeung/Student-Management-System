#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Student.h"


int main(void){

    School school;
    initSchool(&school);
    readFile(&school);
    showStudent(&school);
    // testing filter
    FilterList filterList;
    // showFilter(&filterList);
    initFilter(&school,&filterList);
    showFilter(&filterList);
    return 0;
}