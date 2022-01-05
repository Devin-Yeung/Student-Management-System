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


enum Discipline {ENGLISH, CHINESE, MATH, OUTCLASS};


// Data operations
void initSchool(School * school);
void addStudent(Student * stu, School * school);
void delStudent(Student * stu, School * school);
void showStudent(School * school);





// filter
void initFilter (School * school, FilterList * filterList);
void reinitFilter(FilterList * filterList);
void destoryFilter(FilterList * filterList);
void addFilter(Filter * filter, FilterList * filterList);
void delFilter(Filter * filter, FilterList * filterList);
Filter * mergeFilter(Filter * f1, Filter * f2);
Filter * toSortFilter(Filter * head, Filter * tail);
void sortFilter(FilterList * filterList);
void showFilter(School * school, FilterList * filterList);
void filterByClass(int class, FilterList * filterList);
void filterByName(char * name, FilterList * filterList);
void filterByYear(int year, FilterList * filterList);
void filterByMajor(char * major, FilterList * filterList);
void delByFilter (School * school, FilterList * filterList);
void keepByFilter(School * school, FilterList * filterList);





// UI
void addStudentUI(School * school);
void modifyStudentUI(School * school, FilterList * filterList);
void multiFilterUI (School * school);
void filterByClassUI(FilterList * filterList);
void filterByYearUI(FilterList * filterList);
void filterByNameUI(FilterList * filterList);
void filterByMajorUI(FilterList * filterList);
void getNameUI(Student * pstu);
void getMajorUI (Student * pstu);
void getYearUI(Student * pstu);
void getClassUI (Student * pstu);
void getScoreUI(enum Discipline discipline, Student * pstu);
void StatGpaByIntervalUI (FilterList * filterList);






// stat
void showStat(FilterList * filterList);
void statGpaByInterval(int interval, FilterList * filterList);




// file operation
void readFile (School * school);
void writeFile (School * school);
void backup(void);



// login module
void passwd_to_string_hash(char * passwd, char string[65]);

#endif