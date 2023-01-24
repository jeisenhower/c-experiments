#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t exp(int base, int power);
uint64_t descendingOrder(uint64_t n);

int main() {

    uint64_t num = 10895;
    printf("%d\n", descendingOrder(num));

    printf("%d\n", exp(6, 3));
    return 0;
}

uint64_t exp(int base, int power) {

    uint64_t total = 1;

    for (int i=1; i<=power; i++) {
        total = total * base;
    }

    return total;
}

uint64_t descendingOrder(uint64_t num) {
    // Get the number of digits in the input value
    uint64_t tmp = num;
    int num_digits = 0;
    uint64_t highest_value = 0;
    while(tmp > 0) {
        tmp /= 10;
        num_digits++;
    }

    // Store digits in an array of ints
    int* digits = calloc(num_digits, sizeof(int));
    for (int i=0; i<num_digits; i++) {
        *(digits+i) = num % 10;
        num /= 10;
    }


    // Sort the array so that the smallest value is first
    // and the largest value is last in the array
    int temp;
    for (int i=0; i<num_digits-1; i++) {

        for (int j=i+1; j<num_digits; j++) {
            if (*(digits+i) > *(digits+j)) {
                // Swap the values
                temp = *(digits+j);
                *(digits+j) = *(digits+i);
                *(digits+i) = temp;
            }
        }
    }

    // Take the sorted array and multiply each entry of the array
    // by the appropriate base 10 exponent (based on its position
    // in the array)
    uint64_t descending = 0;
    for (int i=0; i<num_digits; i++) {
        printf("%d\n", *(digits+i));
        descending += *(digits+i) * (exp(10, i));
    }


    return descending;
}
