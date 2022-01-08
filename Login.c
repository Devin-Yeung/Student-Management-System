#include "sha-256.h"
#include "Login.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// convert a given string to hash using sha256
void cal_string_hash(char * original_string, char hash_string[65]){
    memset(hash_string,0,sizeof(char[65]));
    // cal hash
    uint8_t hash[32];
    memset(&hash,0,sizeof(uint8_t[32]));
    calc_sha_256(hash, original_string, strlen(original_string));
    // hash to string
	for (size_t i = 0; i < 32; i++) {
        // print out the char an advance the pointer
		hash_string += sprintf(hash_string, "%02x", hash[i]);
	}
    return;
}





// digest are generated according to the hashed passwd and the basic info(the most important one is usr group info),which can be used to check the data integrity.
// the length of digest is given by the sha256 algo
void cal_digest(Usr * usr, char digest[65]){
    memset(digest,0,sizeof(char[65]));
    char usrInfo[512]; // we assume that the total length of usr info does not exceed 512 bits
    memset(usrInfo,0,sizeof(char[512]));
    char * pinfo = usrInfo;
    pinfo += sprintf(pinfo, "%s", usr -> usrName);
    pinfo += sprintf(pinfo, "%d", usr -> usrGroup);
    pinfo += sprintf(pinfo, "%s", usr -> major);
    pinfo += sprintf(pinfo, "%d", usr -> class);
    pinfo += sprintf(pinfo, "%d", usr -> year);
    pinfo += sprintf(pinfo, "%s", usr -> hashedPasswd);
    cal_string_hash(usrInfo,digest);
    return;
}





void initUsr(UsrList * usrList){
    usrList -> head = NULL;
    usrList -> tail = NULL;
    return;
}





void addUsr(Usr * usr, UsrList * usrList){
    // check if UsrList is empty
    if(usrList -> head == NULL){
        usrList -> head = usr;
        usrList -> tail = usr;
        usr -> pre = NULL;
        usr -> next = NULL;
    }
    else{
        // link previous tail to the new node
        usrList -> tail -> next = usr;
        // set the next node of the new node
        usr -> next = NULL;
        // set the previous node of current node
        usr -> pre = usrList -> tail;
        // reset the tail node of the list
        usrList -> tail = usr;
    }
    return;
}





void delUsr(Usr * usr, UsrList * usrList){
    if(usrList == NULL){
        return;
    }

    // if the deleted usr is the first usr in the list
    if(usr == usrList -> head){
        // which means there is only one usr in the list
        if(usrList -> head == usrList -> tail){
            // reset head and tail
            usrList -> head = NULL;
            usrList -> tail = NULL;
            free(usr);
            return;
        }
        
        // reset head
        usrList -> head = usr -> next;
        free(usr);
    }
    // if the deleted usr is the last Usr in the list
    else if(usr == usrList -> tail){
        Usr * preusr = usr -> pre;
        preusr -> next = NULL;
        usrList -> tail = preusr;
        free(usr);
    }
    // if the deleted usr is NOT the first usr or the last usr in the list
    else {
        Usr * preusr = usr -> pre;
        Usr * nextusr = usr -> next;
        preusr -> next = nextusr;
        nextusr -> pre = preusr;
        free(usr);
    }
}





_Bool login(char * usrName, char * passwd, Usr * currentUsr, UsrList * usrList){

    // check if is admin usr
    if(strcmp(usrName,"admin") == 0){
        if(strcmp("admin",passwd) == 0){
            Usr rootUsr = {"admin", SUPER, "ALL", 0, 0};
            rootUsr.next = NULL;
            rootUsr.pre = NULL;
            *currentUsr = rootUsr;
            printf("@@@  LOGIN AS ROOT  @@@\n");
            return 1;
        }
        else {
            printf("密码错误,请重新登录或注册新用户\n");
            return 0;
        }
    }


    if (usrList -> head == NULL){
        printf("未找到该用户,请先注册!\n");
        return 0;
    }

    // walk through the usrList
    Usr * pusr = usrList -> head;
    // check if usr exist
    _Bool haveThisUsr = 0;
    while(pusr != NULL){
        if(strcmp(pusr -> usrName,usrName) == 0){
            haveThisUsr = 1;
            break;
        }
        // advance pointer
        pusr = pusr -> next;
    }

    if(haveThisUsr == 0){
        printf("未找到该用户,请先注册!\n");
        return 0;
    }

    // check data integrity
    char digest[65];
    cal_digest(pusr,digest);
    if( strcmp(pusr -> digest,digest) != 0 ){
        printf("检测到用户信息被恶意篡改,自动从系统中删除该用户\n");
        delUsr(pusr,usrList);
        return 0;
    }

    // check passwd
    char hashedPasswd[65];
    cal_string_hash(passwd,hashedPasswd);
    if( strcmp(pusr -> hashedPasswd, hashedPasswd) == 0){
        *currentUsr = *pusr;
        printf("@@@  LOGIN SUCCESSFULLY  @@@\n");
        return 1;
    }
    else {
        printf("密码错误,请重新登录或注册新用户\n");
        return 0;
    }

}