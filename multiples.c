#include <stdio.h>
#include <stdlib.h>

int contains(int* list, int num);

// Takes in a number and finds all numbers below the given number
// that are either multiples of 3 or 5 and outputs those numbers'
// sum. Numbers that are both multiples of 3 and 5 are counted only
// once.
int multiples(int num);

int main() {

    int mynum = 10;

    printf("%d\n", multiples(mynum));

}

// Takes in an array that is terminated by the first zero present in the array
// (I initialized the array to contain no zeros other than the parts that aren't being
// used)
int contains(int* list, int num) {
    for(int* p=list; *p != 0; p++) {
        if (*p == num) {
            return 1;
        } else if (*p == 0) {
            return 0;
        }
    }

    return 0;
}

/*int multiples(int num) {
    int* multiples = calloc(num/2, sizeof(int));
    int iterated_num = 1;

    int sum = 0;
    int i = 0;
    while(iterated_num < num) {
        if ((iterated_num % 3 == 0 || iterated_num % 5 == 0) && !contains(multiples, iterated_num)) {
            *(multiples + i) = iterated_num;
            sum += iterated_num;
        }

        i++;
        iterated_num++;
    }

    return sum;
}*/

int multiples(int num) {
    int iterated_num = 1;

    int sum = 0;
    int i = 0;
    while(iterated_num < num) {
        if ((iterated_num % 3 == 0 || iterated_num % 5 == 0)) {
            sum += iterated_num;
        }

        i++;
        iterated_num++;
    }

    return sum;
}

