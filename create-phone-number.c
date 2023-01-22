#include <stdio.h>
#include <stdlib.h>


/*
Write a function that accepts an array of 10 integers (between 0 and 9),
 that returns a string of those numbers in the form of a phone number.

 create_phone_number(phnum, (const unsigned char[]){1,2,3,4,5,6,7,8,9,0});
     phnum <- "(123) 456-7890"



The returned format must be correct in order to complete this challenge.

Don't forget the space after the closing parentheses!

*/

char *create_phone_number(char phnum[15], const unsigned char nums[10]);

int main() {

    int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    //int numbers[10];
    char phnum[15];
    //printf("%s\n", "Enter your phone number: ");

    /*for (int i=0; i<10; i++) {
        scanf("%d", &numbers[i]);
    }*/

    char* phone_number = create_phone_number(phnum, numbers);

    printf("%s\n", phone_number);
    return 0;
}

/*
char* create_phone_number(char phnum[15], const unsigned char nums[10]) {
    int* p = (int*)nums;
    // const unsigned char can be type cast to an int
    for (int i=0; i < 14; i++) {
        if (i == 0) phnum[i] = '(';
        else if (i == 4) phnum[i] = ')';
        else if (i == 5) phnum[i] = ' ';
        else if (i == 9) phnum[i] = '-';
        else if (i == 14) phnum[i] = '\0';
        else {
            phnum[i] = *p + '0';
            p++;
        }
    }

    return phnum;
}*/

char* create_phone_number(char phnum[15], const unsigned char nums[10]) {
    char* p = (char*)nums;
    printf("%c\n", *p);

    for (int i=0; i < 14; i++) {
        if (i == 0) phnum[i] = '(';
        else if (i == 4) phnum[i] = ')';
        else if (i == 5) phnum[i] = ' ';
        else if (i == 9) phnum[i] = '-';
        else if (i == 14) phnum[i] = '\0';
        else {
            phnum[i] = (char)*p;
            printf("%c\n", (char)*p);
            p++;
        }
    }

    return phnum;
}
