#include <stdio.h>
#include <stdlib.h>

unsigned decode_roman(const char* roman_number);
unsigned decode_roman_alt(const char* roman_number);

int main() {
    printf("%d\n", decode_roman_alt("IV"));
    return 0;
}

unsigned decode_roman(const char* roman_number) {
    int total = 0;
    int previous = 0;
    int current = 0;
    for (char* p=roman_number; *p != '\0'; p++) {
        switch (*p) {
            case 'I':
                printf("%s\n", "Case I");
                current = 1;
                break;
            case 'V':
                printf("%s\n", "Case V");
                current = 5;
                break;
            case 'X':
                current = 10;
                break;
            case 'L':
                current = 50;
                break;
            case 'C':
                current = 100;
                break;
            case 'D':
                current = 500;
                break;
            case 'M':
                current = 1000;
                break;
        }

        if (current > previous) {
            total += (current - (previous*2));
        } else {
            total += current;
        }

        previous = current;
    }

    return total;
}


unsigned decode_roman_alt (const char *roman_string)
{
	static const short roman_numbers[] = {
		['I'] = 1, ['V'] = 5, ['X'] = 10, ['L'] = 50, ['C'] = 100, ['D'] = 500, ['M'] = 1000
	};
	int number = 0;

	for (; *roman_string; roman_string++) {
		unsigned  cur_value = roman_numbers[(unsigned char) (roman_string[0])];
		unsigned next_value = roman_numbers[(unsigned char) (roman_string[1])];

// roman_numbers['\0'] will be 0, so this works
		number += (next_value > cur_value) ? -cur_value : +cur_value;
	}
	return number;
}
