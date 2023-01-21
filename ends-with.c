#include <stdio.h>
#include <stdbool.h>

bool endsWith(const char *string, const char *ending) {
    // Initialize string lengths to zero
    int endLen = 0;
    int stringLen = 0;

    // Find the length of the ending and iterate through until the end of the string
    while (*ending != '\0') {
        endLen++;
        ending++;
    }

    // Check that the ending is not null (the  string has no length)
    if (endLen == 0) {
        return true;
    }

    // Find the length of the string and iterate through until the end of the string
    while (*string != '\0') {
        stringLen++;
        string++;
    }

    // If the ending is longer than the initial string, return false
    if (endLen > stringLen) {
        return false;
    }

    // decrement from the null character to the last character of the string for both ending and inital strings
    string--;
    ending--;

    // For the length of the ending string, check that each of its characters match the ending characters of the initial string
    for (int i=endLen; i>0; i--) {
        if (*string != *ending) {
            return false;
        }

        string--;
        ending--;
    }

    return true;

}


int main() {

    char* myString = "abcd";
    char* ending = "bcd";

    bool endMatches = endsWith(myString, ending);

    printf("%d\n", endMatches);

    return 0;
}
