#ifndef _STUDENT_H_ 
#define _STUDENT_H_ 

// define the length of name
#define NAMELEN 16
// define the length of major
#define MAJORLEN 32



typedef struct Student{
    int year;
    int class;
    char name[NAMELEN];
    char major[MAJORLEN];
    float math;
    float english;
    float chinese;
    float inclass;
    float outclass;
    float gpa;
    struct Student * pre;
    struct Student * next;
} Student;



typedef struct School{
    Student * head;
    Student * tail;
} School;





typedef struct Filter {
    Student * stu;
    struct Filter * pre;
    struct Filter * next;
} Filter;



typedef struct FilterList {
    Filter * head;
    Filter * tail;
} FilterList;





typedef struct Major{
    char title[MAJORLEN];
    struct Major * next;
} Major;





// Data operations
void initSchool(School * school);
void addStudent(Student * stu, School * school);
void delStudent(Student * stu, School * school);
void showStudent(School * school);





// filter
void initFilter (School * school, FilterList * filterList);
void destoryFilter(FilterList * filterList);
void addFilter(Filter * filter, FilterList * filterList);
void delFilter(Filter * filter, FilterList * filterList);
void showFilter(FilterList * filterList);
void filterByClass(int class, FilterList * filterList);
void filterByName(char * name, FilterList * filterList);
void filterByYear(int year, FilterList * filterList);
void filterByMajor(char * major, FilterList * filterList);






// UI
void addStudentUI(School * school);
void multiFilterUI (School * school);
void filterByClassUI(FilterList * filterList);
void filterByYearUI(FilterList * filterList);
void filterByNameUI(FilterList * filterList);
void filterByMajorUI(FilterList * filterList);






// file operation
void readFile (School * school);




#endif