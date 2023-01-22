#include <stdio.h>
#include <stdlib.h>

int jstrlen(char* str);
char* reverse_str(char* str);

int main() {

    char* mystr = "hello";

    //printf("%d\n", jstrlen(mystr));

    printf("%s\n", reverse_str("redrum"));

    return 0;
}

int jstrlen(char* str) {
    int len = 0;
    for (char* p=str; *p != '\0'; p++) {
        len++;
    }

    return len;
}

char* reverse_str(char* str) {
    int len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    str--;

    // NOTE: I believe if I were to use calloc, we would not need to
    // set the last value of the allocated memory equal to the null character,
    // but I believe that it is safest practice to do so here because we cannot
    // guarantee that on every system, each byte in the allocated memory will be
    // initialized to zero (or the null character). It just so happens that on
    // my system, this seems to be the case (most likely due to my operating
    // system's security practices), but it may not be on all systems. It really
    // should be better to use calloc instead in order to initialize all blocks
    // to zero.
    /*char* reverse = malloc((len+1) * sizeof(char));
    *(reverse + len) = '\0';*/

    char* reverse = calloc(len+1, sizeof(char));

    for (int i=0; i<len; i++) {
        *(reverse+i) = *str;
        str--;
    }

    return reverse;

}
