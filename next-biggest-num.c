#include <stdio.h>
#include <stdlib.h>

/*

Create a function that takes a positive integer and returns the next bigger number that can be formed by rearranging its digits. For example:

12 ==> 21
513 ==> 531
2017 ==> 2071

nextBigger(num: 12)   // returns 21
nextBigger(num: 513)  // returns 531
nextBigger(num: 2017) // returns 2071

If the digits can't be rearranged to form a bigger number, return -1 (or nil in Swift):

9 ==> -1
111 ==> -1
531 ==> -1

nextBigger(num: 9)   // returns nil
nextBigger(num: 111) // returns nil
nextBigger(num: 531) // returns nil

*/


int charToInt(char c);

char intToChar(int digit);

// Raises an integer a to the positive power of b
long long pwr(int a, int b);

char* cpy_str(char* str);

int strings_equal(char* str1, char* str2);

int count_digits(long long n);

long long next_bigger_number(long long n);

int main() {
    //printf("%d\n", count_digits(13568952));
    printf("%d\n", next_bigger_number(10980));
    printf("%d\n", next_bigger_number(2017));
    //printf("%d\n", next_bigger_number(12));
    //printf("%d\n", next_bigger_number(21));
    //printf("%ul\n", next_bigger_number(2099063673373557041));
    //printf("%d\n", next_bigger_number(59884848459853));
    return 0;
}

int charToInt(char c) {
    int digit;
    switch(c) {
            case '0':
                digit = 0;
                break;
            case '1':
                digit = 1;
                break;
            case '2':
                digit = 2;
                break;
            case '3':
                digit = 3;
                break;
            case '4':
                digit = 4;
                break;
            case '5':
                digit = 5;
                break;
            case '6':
                digit = 6;
                break;
            case '7':
                digit = 7;
                break;
            case '8':
                digit = 8;
                break;
            case '9':
                digit = 9;
                break;
        }

    return digit;
}

char intToChar(int digit) {
    char result;
    switch(digit) {
            case 0:
                result = '0';
                break;
            case 1:
                result = '1';
                break;
            case 2:
                result = '2';
                break;
            case 3:
                result = '3';
                break;
            case 4:
                result = '4';
                break;
            case 5:
                result = '5';
                break;
            case 6:
                result = '6';
                break;
            case 7:
                result = '7';
                break;
            case 8:
                result = '8';
                break;
            case 9:
                result = '9';
                break;
        }

    return result;
}

char* cpy_str(char* str) {
    char* ch = str;
    int size = 0;
    while (*ch != '\0') {
        size++;
        ch++;
    }

    char* cpy = malloc((size + 1) * sizeof(char));
    char* p = cpy;
    for (int i=0; i<=size; i++) {
        *p = *str;
        str++;
        p++;
    }

    return cpy;

}

int strings_equal(char* str1, char* str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) return 0;
        str1++;
        str2++;
    }

    if (*str1 != *str2) return 0;

    return 1;
}

long long pwr(int a, int b) {
    long long total = 1;
    for (int i=0; i<b; i++) {
        total *= a;
    }

    return total;
}

int count_digits(long long n) {
    int digits = 0;
    while (n > 0) {
        n /= 10;
        digits++;
    }

    return digits;
}
/*
n =         59884848459853
actual =    59884848485539
expected =  59884848483559
*/


long long next_bigger_number(long long n) {
    long long next_biggest = 0;

    int digit_count = count_digits(n);

    // Check if the number is only one digit long
    if (digit_count <= 1) return -1;

    // Initialize the memory block to be the digit count + 1 to account for the terminating char
    char* digits = malloc((digit_count + 1) * sizeof(char));
    char* digit_ptr = digits;

    // Create a second memory block of same size to form a copy of the string
    char* result = malloc((digit_count+1) * sizeof(char));
    char* res_ptr = result;

    // Create a string (array of chars) representing the number
    int digit;
    long long power;
    for (int i=digit_count-1; i>=0; i--) {
        power = pwr(10, i);
        digit = n / pwr(10, i);
        *digit_ptr = intToChar(digit);
        *res_ptr = intToChar(digit);

        n -= digit * power;
        digit_ptr++;
        res_ptr++;
    }

    // Add terminating char to end of string
    *digit_ptr = '\0';
    digit_ptr--;
    *res_ptr = '\0';
    res_ptr--;

    // At this point, we know that it is possible to produce a next biggest number.
    char tmp;
    int index = digit_count;
    while (index > 0) {
        if (charToInt(*res_ptr) > charToInt(*(res_ptr-1))) {

            // Found where to swap digits. Iterate through to find the digit to the right of the swapping point that is closest
            // but still greater than the digit we are going to swap out.

            // swap the two values in the array, then check if there are any values less than the value at res_ptr-1 but still greater than the
            // value at res_ptr
            char next_largest = *res_ptr;
            tmp = *(res_ptr-1);
            *(res_ptr-1) = *res_ptr;
            *res_ptr = tmp;


            // Iterate through the oppposite direction to find the next largest digit
            char* p = res_ptr;
            while (*p != '\0') {
                // If the temp pointer p is less than our current next largest but still greater than the next digit value (stored at *(resArr-1)
                if ((charToInt(*p) < charToInt(*(res_ptr-1))) && (charToInt(*p) > charToInt(*res_ptr))) {
                    // Swap the values
                    tmp = *(res_ptr-1);
                    *(res_ptr-1) = *p;
                    *p = tmp;
                }

                p++;
            }

            break;
        }

        res_ptr--;
        index--;
    }

    // Check if the strings are still equal. If they are, return -1
    if (strings_equal(digits, result)) return -1;


    // Form the lowest number possibel by putting the lowest digits first and the highest digits last in the number
    while (*(res_ptr+1) != '\0') {
        char* p = res_ptr+1;
        while (*p != '\0') {
            if (charToInt(*p) < charToInt(*res_ptr)) {
                // swap the two values
                tmp = *p;
                *p = *res_ptr;
                *res_ptr = tmp;
            }
            p++;
        }

        res_ptr++;
    }

    // Convert the swapped array into a number
    for (int i=digit_count-1; i>=0; i--) {
        next_biggest += pwr(10, i) * (charToInt(*(result)));
        result++;
    }


    return next_biggest;

}
