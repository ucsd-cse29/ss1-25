#include <stdio.h>
#include <stdint.h>

void print_abc_int(char c) {
    for (int i = 0; i < 3; i++) {
        if (i == 0) {
            printf("%c %d\n", c, c);
        } else if (i >= 1) {
            printf("%c %d\n", c + i, c + i);
        }
        // printf("%c %d\n", c + i, c + i);

    }

}

uint8_t bin8_to_dec(char bin_arr[]) {
    // Given a char array with a binary number
    // e.g., ['0', '0', ... , '1'] of size 8
    // return the decimal value
    // Example: [ 0,0,0,0,0,0,0,1] -> return 1

}


int main() {
    // This is a comment. I just wrote hello
    // puts("Hello world!");
    /* This is a long
     * block comment
     * across many lines
     */

    printf("%s\n", "Hello world!");
    // int a = 1;
    char a = 'a';
    print_abc_int(a);

    return 0;

}






