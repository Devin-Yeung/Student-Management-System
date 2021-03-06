#include "Student.h"

#ifndef _LOGIN_H_
#define _LOGIN_H_

// define the maximum passwd length
#define PASSWDLEN 128

// only super usr can add an teacher account
// both super and teacher can add an student account
enum UsrGroup {SUPER, TEACHER, STUDENT};

typedef struct Usr {
    char usrName[NAMELEN]; // NAMELEN is defined in Student.h
    enum UsrGroup usrGroup;
    char major[MAJORLEN]; //if major == ALL means you are accesssible to the info in all major(usually root) MAJORLEN is defined in Student.h
    int class; // if year == 0 means you are accessible to the info in all class
    int year; //if year == 0 means you are accessible to the info in all grade
    char hashedPasswd[65]; // the length of hashedPasswd is given by the sha256 algo (which is a fixed lenght)
    char digest[65]; // the length of digest is given by the sha256 algo (which is a fixed lenght)
    struct Usr * next;
    struct Usr * pre;
} Usr;



typedef struct UsrList {
    Usr * head;
    Usr * tail;
} UsrList;





// usr management part
void initUsr(UsrList * usrList);
void addUsr(Usr * usr, UsrList * usrList);
void delUsr(Usr * usr, UsrList * usrList);
_Bool login(char * usrName, char * passwd, Usr * currentUsr, UsrList * usrList);



// crypto module
void cal_string_hash(char * original_string, char hash_string[65]);
void cal_digest(Usr * usr, char digest[65]);



// UI
void addUsrUI(Usr * usr, UsrList * usrList);
_Bool loginUI (Usr * currentUsr, UsrList * usrList);
_Bool usrLoginUI (Usr * usr, UsrList * usrList);



// File operations
void readUsr (UsrList * usrList);
void writeUsr (UsrList * usrList);



#endif