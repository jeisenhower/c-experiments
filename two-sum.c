#include <stdio.h>
#include <stdlib.h>

/*
Write a function that takes an array of numbers (integers for the tests) and a target number. It should find two different items in the array that,
when added together, give the target value. The indices of these items should then be returned in a tuple / list (depending on your language) like so: (index1, index2).

For the purposes of this kata, some tests may have multiple answers; any valid solutions will be accepted.

The input will always be valid (numbers will be an array of length 2 or greater, and all of the items will be numbers; target will always be the sum of two different items from that array).
*/

void twoSum(unsigned count, const int numbers[count], int target, unsigned *index1, unsigned *index2);

int main() {
    int index1 = 0;
    int index2 = 0;
    int numbers[] = {5, 6, 1, 8, 12};

    twoSum(5, numbers, 20, &index1, &index2);

    printf("(%d, %d)\n", index1, index2);
    return 0;
}

void twoSum(unsigned count, const int numbers[count], int target, unsigned *index1, unsigned *index2) {
    for (int i=0; i<count; i++) {
        for (int j=i+1; j<count; j++) {
            if (numbers[i] + numbers[j] == target) {
                *index1 = i;
                *index2 = j;
                break;
            }
        }
    }
}
