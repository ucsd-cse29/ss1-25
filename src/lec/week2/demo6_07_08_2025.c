#include <stdio.h>
#include <stdint.h>

void swap_by_val(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap_by_ptr(int *a, int*b) {
    int temp = *a;
    *a = *b;
    *b = temp;

}

void encode2(uint32_t num, char result[]) {
    // Working on the 2nd byte
    uint32_t snd_byte = 0x3f & num; // last 6 bits
    uint32_t fst_byte = 0x1f & (num >> 6); // top 5 bits
    snd_byte = snd_byte | 0x80;
    fst_byte = fst_byte | 0xC0;
    result[0] = fst_byte;
    result[1] = snd_byte;
}

int main(int argc, char *argv[]) {
    // int num = 42;
    // int *pnum = &num;
    // int *b = pnum;
    // printf("&num = %p\n", &num);
    // printf("pnum = %p\n", pnum);
    // printf("b = %p\n", b);
    // printf("&pnum = %p\n", &pnum);

    //int a = 0;
    //int b = 1;
    //printf("Pre swap a = %d b = %d\n", a, b);
    //swap_by_val(a, b);
    //printf("Post swap a = %d b = %d\n", a, b);
    //printf("Swap by ptr\n");
    //printf("Pre swap a = %d b = %d\n", a, b);
    //swap_by_ptr(&a, &b);
    //printf("Post swap a = %d b = %d\n", a, b);

    uint32_t num = 128;
    char result[2];
    encode2(num, result);
    for (int i = 0; i < 2; i++) {
        printf("%02X ", (unsigned char) result[i]);
    }

}
