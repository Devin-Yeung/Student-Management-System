#include "sha-256.h"
#include <stdio.h>
#include <string.h>


// convert password to hash using sha256
void passwd_to_string_hash(char * passwd, char string[65]){
    memset(string,0,sizeof(char[65]));
    // cal hash
    uint8_t hash[32];
    memset(&hash,0,sizeof(uint8_t[32]));
    calc_sha_256(hash, passwd, strlen(passwd));
    // hash to string
	for (size_t i = 0; i < 32; i++) {
		string += sprintf(string, "%02x", hash[i]);
	}
    return;
}