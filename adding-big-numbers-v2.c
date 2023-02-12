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

char* formatStr(const char* num, int formatted_str_len);

char* add(const char* a, const char* b);


int main() {
    printf("%s\n", add("6276632695252793654356", "7116"));
    //printf("%s\n", add("888", "222"));
    //printf("%s\n", add("63829983432984289347293874", "90938498237058927340892374089"));
    //printf("%s\n", "91002328220491911630239667963");
    //printf("%s\n", formatStr("123456789", 10));
    return 0;
}


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
char* formatStr(const char* num, int formatted_str_len) {
    // Get to end of the string for both num and dest
    int num_len = 0;
    //char* formattedStr = calloc(formatted_str_len+1, sizeof(char));
    char* formattedStr = malloc((formatted_str_len+1) * sizeof(char));


    while(*num != '\0') {
        num++;
        num_len++;
    }

    for (int i=0; i<formatted_str_len; i++) {
        *formattedStr = '0';
        formattedStr++;
    }

    for (int i=0; i<=num_len; i++) {
        *formattedStr = *num;
        formattedStr--;
        num--;
    }

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

    //char* formatted_string;

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
        num_result_digits = digits_b + 2;
        num_digits = digits_b;
        // Format the shorter string so that it has the same length but with leading spaces filled with zeros,
        // so we can properly do the calculation
        num_a = formatStr(a, digits_b);
        // Above I attempted to set the pointer to b equal to the newly created string that has the leading zeros
    } else if (digits_a > digits_b) {
        num_result_digits = digits_a + 2;
        num_digits = digits_a;
        num_b = formatStr(b, digits_a);
    }
    else {
        num_result_digits = digits_a+2;
        num_digits = digits_a;
    }



    char* result = malloc((num_result_digits + 1) * sizeof(char));
    for (int i=0; i<num_result_digits; i++) {
        *result = '0';
        result++;
    }

    *result = '\0';
    result--;

    // Iterate back one position from the terminating char
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
        if (sum >= 10) {
            carry = 1;
            sum -= 10;
        } else {
            carry = 0;
        }

        // Store the result in the result string
        *result = intToChar(sum);
        result--;
        num_a--;
        num_b--;
    }

    if (carry > 0) {
        *result = intToChar(carry);
        result--;
    }

    // Format the output so there are no leading zeros for the number
    int leading = 0;
    while(*result == '0') {
        result++;
        leading++;
    }

    if (leading > 0) {
        char* ret_str = malloc((num_result_digits + 1 - leading) * sizeof(char));
        for (int j=0; j<=num_result_digits-leading+1; j++) {
            *(ret_str + j) = *(result+j);
        }


        return ret_str;
    } else {
        return result;
    }




}
