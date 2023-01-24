#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool is_pangram(const char* str);

int main() {

    const char* sentence = "The quick brown fox jumps over the lazy dog";
    printf("%d\n", is_pangram(sentence));

    return 0;
}

bool is_pangram(const char* str) {
    char abc[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for (int i=0; i<26; i++) {
        bool hasLetter = false;
        // Check if each letter is in the provided string
        for (const char* p = str; *p != '\0'; p++) {
            if (*p == ' ' || *p == '-' || *p == '.') continue;
            else if ((tolower(*p)) == *(abc+i)) {
                hasLetter = true;
                break;
            }
        }

        if (!hasLetter) return false;
    }

    return true;
}
