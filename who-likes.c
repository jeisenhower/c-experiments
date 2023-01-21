#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Get string length
int jstrlen(char* str) {
    int len = 0;

    while(*str != '\0') {
        len++;
        str++;
    }

    return len;
}

// Copy contents of str to cpy
char* jstrcpy(const char* str) {
    char* cpy;
    int len = 0;
    // Get length of original string
    while(*(str+len) != '\0') {
        len++;
    }

    // Allocate memory based on string length
    // NOTE: Add 1 to account for the terminating null character
    cpy = malloc((len+1) * sizeof(char));

    // Copy each character into the
    int i = 0;
    for (i; *(str+i) != '\0'; i++) {
        *(cpy+i) = *(str+i);
    }

    *(cpy+i) = '\0';

    return cpy;
}

char* jconcat(char* str1, char* str2) {
    // Concatenate two strings to result in one returned string
    int len1 = jstrlen(str1);
    int len2 = jstrlen(str2);

    char* newStr = malloc((len1+len2+1)*sizeof(char));
    int i = 0;
    for (i; i<len1; i++) {
        *(newStr+i) = *(str1+i);
    }

    int j=0;
    for (j; j<(len2); j++) {
        *(newStr+i+j) = *(str2+j);
    }

    *(newStr+i+j) = '\0';

    return newStr;
}

char* likes(size_t n, const char* const names[n]) {

    char* pointer;

    int size = (int)n;

    switch(size) {
        case 0:
            return "no one likes this";

        case 1:
            pointer = &names[0];
            int len = 11;
            for (int i=0; *(names+i) != '\0'; i++) {
                len++;
            }

            char* statement = malloc(sizeof(char)*len);

            for (int i=0; *(names+i) != '\0'; i++) {
                //*pointer = *(statement+i);
                *(statement+i) = *(names+i);
            }

            //*pointer = *pointer + " likes this";
            return statement;
    }

}

// Takes a pointer to an array of characters that specify direction to take. Each direction specifies you walk for one minute in the
// specified direction.
bool isValidWalk(const char* walk) {
    int walkLen = jstrlen(walk);
    if (walkLen != 10) {
        return false;
    }

    return true;

}

int main() {

    /*const char* const names[1] = {"mike"};
    char* result = likes(1, names);
    printf("%s", result);*/

    char* str1 = "hello ";

    char* str2 = jstrcpy(str1);

    //printf("%s\n", str2);

    char* str3 = jconcat(str1, str2);

    char* myStr = jconcat("Bob", " likes this");

    printf("%s\n", myStr);

    bool walk = isValidWalk("newnsenwe");

    printf("%d\n", walk);

    return 0;
}
