#include <stdlib.h>
#include <stdio.h>

/*

NOTE ON THE PROJECT: This code works for the most part. I used unsigned long long ints to start, but that data type wasn't big enough to store the huge numbers that the test
suite ran. I am thinking the only real solution to this is to actually break down this problem into manual addition as you would do on paper. So we would convert each character
in the array to an int and add those ints and then display the final result as a very large string. This way we can avoid adding extremely large numbers, which c is not really
the ultimate language for doing.


We need to sum big numbers and we require your help.

Write a function that returns the sum of two numbers. The input numbers are strings and the function must return a string.
Example

add("123", "321"); // returns "444"
add("11", "99");   // returns "110"

Notes

    The input numbers are big.
    The input is a string of only digits
    The numbers are positives


*/

int toInt(char c);

char intToChar(int digit);

char* formatStr(char* num, int formatted_str_len);

char* longDoubleToString(long double num);

char* add(const char* a, const char* b);

long double power(int a, int b);

long double toLongDouble(const char* str);


int main() {
    //printf("%Lf\n", power(10, 25));
    //printf("%llu\n", toLongLong("63829983432984289347293874"));
    //printf("%llu\n", add("123", "321"));
    //printf("%s\n", longLongToString(1234567));
    printf("%s\n", add("63829983432984289347293874", "90938498237058927340892374089"));
    //printf("%s\n", formatStr("123456789", 10));
    return 0;
}

long double power(int a, int b) {
    // Raises a to the power of b
    long double total = 1;

    for (int i=0; i<b; i++) {
        total *= a;
    }

    return total;
}

long double toLongDouble(const char* str) {
    long double total = 0;
    const char* digit_char = str;
    int digit_count = 0;

    while (*digit_char != '\0') {
        digit_count++;
        digit_char++;
    }

    unsigned long long int digit;
    for (int i=digit_count-1; i>=0; i--) {
        switch(*str) {
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
                digit =6;
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
        total += (power(10, i) * digit);
        str++;
    }

    return total;

}

char* longDoubleToString(long double num) {
    // Get the number of digits in the num
    int pwr = 0;
    while ((num / power(10, pwr)) >= 10) {
        pwr++;
    }

    char* str = malloc((pwr+2) * sizeof(char));
    char* char_digit = str;
    int digit;
    for (int i=pwr; i>=0; i--) {
        digit = num/power(10, i);

        // Convert the digit into a char
        switch(digit) {
            case 0:
                *char_digit = '0';
                break;
            case 1:
                *char_digit = '1';
                break;
            case 2:
                *char_digit = '2';
                break;
            case 3:
                *char_digit = '3';
                break;
            case 4:
                *char_digit = '4';
                break;
            case 5:
                *char_digit = '5';
                break;
            case 6:
                *char_digit = '6';
                break;
            case 7:
                *char_digit = '7';
                break;
            case 8:
                *char_digit = '8';
                break;
            case 9:
                *char_digit = '9';
                break;
        }
        char_digit++;

        // Subtract the multiplied value of the power times the digit from the num value
        num = num - (digit * power(10, i));
    }

    // Add terminating char
    *char_digit = '\0';

    return str;


}


/*char* add(const char *a, const char *b) {

    long double num_a = toLongDouble(a);
    printf("a as long double: %Lf\n", num_a);
    long double num_b = toLongDouble(b);
    printf("b as long double: %Lf\n", num_b);

    long double total = num_a + num_b;
    printf("Total: %Lf\n", total);

    // Now convert back to a string
    return longDoubleToString(total);

}*/

int toInt(char c) {
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
                digit =6;
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


// Returns a new string with the set length with leading zeros, followed by the
// string that the user wanted to format into the leading zeros form
char* formatStr(char* num, int formatted_str_len) {
    // Get to end of the string for both num and dest
    int num_len = 0;
    //char* formattedStr = calloc(formatted_str_len+1, sizeof(char));
    char* formattedStr = malloc((formatted_str_len+1) * sizeof(char));
    char* alloc_pos = formattedStr;


    while(*num != '\0') {
        num++;
        num_len++;
    }

    for (int i=0; i<formatted_str_len; i++) {
        *alloc_pos = '0';
        alloc_pos++;
    }

    for (int i=0; i<=num_len; i++) {
        *alloc_pos = *num;
        alloc_pos--;
        num--;
    }

    // Iterate to the end of the string and return that as the pointer
    while(*formattedStr != '\0') {
        formattedStr++;
    }

    return formattedStr;
}

char* add(const char* a, const char* b) {
    // Figure out how many digits we will need for the return string
    const char* num_a = a;
    int digits_a = 0;
    const char* num_b = b;
    int digits_b = 0;

    char* formatted_string;

    int num_result_digits;
    int num_digits;

    while(*num_a != '\0') {
        num_a++;
        digits_a++;
    }

    while(*num_b != '\0') {
        num_b++;
        digits_b++;
    }

    // Allocate the necessary memory for the result string and format the shorter string (if there is one) to
    // have the same number of characters as the larger string (if they are not the same size)
    if (digits_b > digits_a) {
        num_result_digits = digits_b+1;
        num_digits = digits_b;
        // Format the shorter string so that it has the same length but with leading spaces filled with zeros,
        // so we can properly do the calculation
        num_a = formatStr(num_a, digits_b);
        // Above I attempted to set the pointer to b equal to the newly created string that has the leading zeros
    } else if (digits_a > digits_b) {
        num_result_digits = digits_a+1;
        num_digits = digits_a;
        num_b = formatStr(num_b, digits_a);
    }
    else {
        num_result_digits = digits_a + 1;
        num_digits = digits_a;
    }



    char* result = malloc((num_result_digits + 1) * sizeof(char));
    for (int i=0; i<num_result_digits; i++) {
        *result = '0';
        result++;
    }

    *result = '\0';
    result--;

    num_a--;
    num_b--;

    // Iterate through the strings and add the numbers
    int carry = 0;
    int digit_a;
    int digit_b;
    int sum;
    for (int i=0; i<num_digits; i++) {
        digit_a = toInt(*num_a);
        digit_b = toInt(*num_b);

        sum = digit_a + digit_b + carry;
        if (result >= 10) {
            carry = 1;
            sum -= 10;
        } else {
            carry = 0;
        }

        // Store the result in the result string
        *result = intToChar(sum);
        result--;
    }

    if (carry > 0) {
        *result = intToChar(carry);
        result--;
    }

    return result;


}
