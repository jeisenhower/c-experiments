#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int jstrlen(const char* str);
char* str_to_lower(const char* str);
bool xo(const char* str);


int main() {
    /*char* mystr = "Hello TheRe";
    char* lowercase = str_to_lower(mystr);

    printf("%s\n", lowercase);*/

    printf("%d\n", xo("xoxxoomxo"));

    return 0;
}


int jstrlen(const char* str) {
    int len = 0;
    for (int i=0; *(str+i) != '\0'; i++) {
        len++;
    }

    return len;
}

char* str_to_lower(const char* str) {
    char* lower = malloc((jstrlen(str) + 1) * sizeof(char));
    for (int i=0; *(str+i) != '\0'; i++) {
        *(lower+i) = *(str+i);
        if (isupper(*(str+i))) {
            printf("%s\n", "entering uppercase");
            *(lower+i) = tolower(*(str+i));
        }
    }

    return lower;
}


// Determines if the number of x's is equal to the number of o's in a given string
/*bool xo(const char* str) {
    // Convert the string to lowercase
    char* lower = str_to_lower(str);

    int xcount = 0;
    int ocount = 0;

    for (int i=0; *(lower+i) != '\0'; i++) {
        if (*(lower+i) == 'x') {
            xcount++;
        } else if (*(lower+i) == 'o') {
            ocount++;
        }
    }

    if (xcount == ocount) {
        return true;
    }

    return false;
}*/

bool xo(const char* str) {
    int xcount=0, ocount=0;

    for (char* p = str; *p; p++) {
        if (tolower(*p) == 'x') xcount++;
        else if (tolower(*p) == 'o') ocount++;
    }

    if (xcount == ocount) return true;
    return false;
}
