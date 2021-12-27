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
    struct Student * next;
} Student;



typedef struct Major{
    char title[MAJORLEN];
    struct Major * next;
} Major;



typedef struct School{
    Student * head;
    Student * end;
} School;



void initSchool(School * school);
void addStudent(Student * stu, School * school);
void addStudentUI(School * school);
void showStudent(School * school);




// file operation

void readFile (School * school);




#endif