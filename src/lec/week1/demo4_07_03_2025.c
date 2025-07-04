#include <stdio.h>
#include <stdint.h>

int main() {
    char str[] = "José";
    
    for (int i = 0; str[i] != 0; i++) {
        printf("0x%x\n", (unsigned char) str[i]);
    }

    uint8_t inp_a = 0b00100111;
    uint8_t inp_b = 0b10101100;
    printf("inp_a | inp_b = 0x%x\n", (unsigned char) (inp_a | inp_b));
    printf("inp_a || inp_b = 0x%x\n", (unsigned char) (inp_a || inp_b));

}


