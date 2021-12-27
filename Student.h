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



typedef struct Major{
    char title[MAJORLEN];
    struct Major * next;
} Major;



typedef struct School{
    Student * head;
    Student * tail;
} School;


// Data operations
void initSchool(School * school);
void addStudent(Student * stu, School * school);
void delStudent(Student * stu, School * school);
void showStudent(School * school);



// UI
void addStudentUI(School * school);



// file operation

void readFile (School * school);




#endif