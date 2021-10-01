
/*

Q) Write two functions which encrypt and decrypt a given string 

*/


#include <stdio.h>

void encrypt(char *str);

void decrypt(char *str);

int main(){

    char string[] = "I am working late tonight";

    encrypt(string);
    
    printf("Encrypted string : %s\n", string);

    decrypt(string);

    printf("Decryted string : %s\n", string);

    return 0;
}


void encrypt(char *str){
    char *ptr = str;

    while (*ptr != '\0'){
        *ptr = *ptr + 2;
        ptr++;
    }
}

void decrypt(char *str){
    char *ptr = str;

    while (*ptr != '\0'){
        *ptr = *ptr - 2;
        ptr++;
    }
}