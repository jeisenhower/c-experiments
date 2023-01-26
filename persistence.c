#include <stdio.h>
#include <stdlib.h>

int numDigits(int num);

int power(int num, int power);

int persistence_recursive(int num, int count);

/*
39 --> 3 (because 3*9 = 27, 2*7 = 14, 1*4 = 4 and 4 has only one digit)
999 --> 4 (because 9*9*9 = 729, 7*2*9 = 126, 1*2*6 = 12, and finally 1*2 = 2)
4 --> 0 (because 4 is already a one-digit number)
*/
int persistence(int num);

int main() {
    printf("%d\n", persistence(25));
    int num = 999;

    return 0;
}

int numDigits(int num) {
    int digit_count = 0;
    while(num > 0) {
        digit_count++;
        num /= 10;
    }

    return digit_count;
}

int power(int num, int power) {
    int total = 1;
    for (int i=1; i<=power; i++) {
        total *= num;
    }

    return total;
}

/*int persistence_recursive(int num, int count) {
    if (num < 10) return count;
    else count++;
    int digit_count = numDigits(num);
    printf("num digits %d\n", digit_count);
    int digit = 0;

    // Separate the number into an array of ints for each digit
    int* digits = malloc(digit_count * sizeof(int));
    int* p = digits;
    for (int i=digit_count-1; i>0; i--) {
        digit = num/(power(10, i));
        *p = digit;
        p++;
        if (num % 10 < 10) *p = num % 10;
        num %= power(10, i);
    }

    int newnum = *digits;
    for (int i=0; i<digit_count-1; i++) {
        newnum = newnum * (*(digits+1));
        digits++;
    }

    if (newnum >= 10) {
        persistence_recursive(newnum, count);
    } else {
        return count;
    }
}

int persistence(int num) {
    return persistence_recursive(num, 0);
}*/

int persistence(int num) {
    int count = 0;
    if (num < 10) return count;
    while (num >= 10) {
        count++;
        int digit_count = numDigits(num);
        printf("num digits %d\n", digit_count);
        int digit = 0;

        // Separate the number into an array of ints for each digit
        int* digits = malloc(digit_count * sizeof(int));
        int* p = digits;
        for (int i=digit_count-1; i>0; i--) {
            digit = num/(power(10, i));
            *p = digit;
            p++;
            if (num % 10 < 10) *p = num % 10;
            num %= power(10, i);
        }

        num = *digits;
        for (int i=0; i<digit_count-1; i++) {
            num = num * (*(digits+1));
            digits++;
        }
    }

    return count;

}


