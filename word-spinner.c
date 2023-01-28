#include <stdio.h>
#include <stdlib.h>

/*
Write a function that takes in a string of one or more words, and returns the same string, but with all five or more
letter words reversed (Just like the name of this Kata). Strings passed in will consist of only letters and spaces.
Spaces will be included only when more than one word is present.

Examples:

spinWords( "Hey fellow warriors" ) => returns "Hey wollef sroirraw"
spinWords( "This is a test") => returns "This is a test"
spinWords( "This is another test" )=> returns "This is rehtona test"


*/

int string_len(const char* str);

char* spin_words(const char* sentence);

void spin_words_alt(const char* sentence, char* result);

int main() {
    //printf("Output: %s\n", spin_words_alt("lorem"));

    char words[30 * 14 + 1];
    spin_words_alt("Hey fellow warriors", (char*)&words);

    printf("the words: %s\n", words);

    return 0;
}

int string_len(const char* str) {
    int len = 0;

    while(*str != '\0') {
        len++;
        str++;
    }

    return len;
}


char* spin_words(const char *sentence) {
    int strlength = string_len(sentence);
    //char *result = calloc((strlength+1), sizeof(char));
    char *result = malloc((strlength+1) * sizeof(char));
    int wordlength = 0;
    const char* pos = sentence;
    char* resptr = result;

    while(*pos != '\0') {
        while(*pos != ' ' && *pos != '\0') {
            wordlength++;
            pos++;
        }

        // If word length is greater than 5, we read it
        // into the result backwards
        if (wordlength >= 5) {
            for (int i=1; i<=wordlength; i++) {
                *resptr = *(pos-i);
                resptr++;
            }

            if (*pos != '\0') {
                *resptr = ' ';
                resptr++;
            }
        } else {
            for (int i=wordlength; i>=0; i--) {
                *resptr = *(pos-i);
                resptr++;
            }
        }

        // Increment past the space if not at the end of the string
        if (*pos != '\0') {
            pos++;
            wordlength = 0;
        }
    }

    return result;

}

void spin_words_alt(const char *sentence, char* result) {
    int wordlength = 0;
    const char* pos = sentence;
    char* resptr = result;

    while(*pos != '\0') {
        while(*pos != ' ' && *pos != '\0') {
            wordlength++;
            pos++;
        }

        // If word length is greater than 5, we read it
        // into the result backwards
        if (wordlength >= 5) {
            for (int i=1; i<=wordlength; i++) {
                *resptr = *(pos-i);
                resptr++;
            }

            if (*pos != '\0') {
                *resptr = ' ';
                resptr++;
            } else *resptr = '\0';
        } else {
            for (int i=wordlength; i>=0; i--) {
                *resptr = *(pos-i);
                resptr++;
            }
        }

        // Increment past the space if not at the end of the string
        if (*pos != '\0') {
            pos++;
            wordlength = 0;
        }
    }

}
