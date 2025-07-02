#include <stdio.h>
#include <stdint.h>


uint8_t bin8_to_dec(char bin_arr[]) {
    // Given a char array holding an unsigned binary
    // value, e.g., [0,0,..., 1], representing 8 bits,
    // return the decimal value it represents
    uint8_t result = 0;
    for (int i = 0; i < 8; i++) {
        uint8_t a = 128;
        for (int j = 0; j < i; j++) {    
            a = a / 2;
        }
        if (bin_arr[i] == '1') {
            result += a;
        }
    }
    return result;
}



int main() {
    
    uint8_t num = 0b11001101;
    printf("%d\n", num);

    char bin_arr[8] = {'1','1','0','0','1','1','0','1'};
    printf("%d\n", bin8_to_dec(bin_arr));

    short int a_s = -1; // 2 bytes
    int a = a_s; // 4 bytes
    printf("a = %d a_s = %d\n", a, a_s);

}



