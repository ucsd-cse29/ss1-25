#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>


uint16_t decode2(char encoding[]) {
    // Take a 2-byte char array of a UTF-8 encoding
    // and produce an integer for that codepoint
    // Reminder: 110yyyyy 10xxxxxx
    // return yyyyyxxxxxx
    uint16_t result = 0;
    uint16_t byte1 = 0;
    uint16_t byte2 = 0;
    if ((encoding[0] & 0b11100000) == 0xC0) {
        byte1 = encoding[0] & 0b00011111;
        byte2 = encoding[1] & 0b00111111;
    } 
    result = (byte1 << 6) | byte2;
    return result;
}


int main(int argc, char* argv[]) {
    // uint16_t codepoint;
    // char e_w_accent[] = "é";
    // codepoint = decode2(e_w_accent);
    // printf("%s should be 233: %hu\n", e_w_accent, codepoint);

    // segfault
    // int *p = 0x0;
    // printf("address: %p\n", p);
    // printf("dereference: %d\n", *p);

    // printf("My CLI args:\n");
    // for (int i = 0; i < argc; i++) {
    //     printf("%s ", argv[i]);
    // }

    pid_t result = fork();

    if (result) {
        printf("Result returned true (%d)\n", result);
        printf("I am parent of child w pid (%d)\n", result);
    } else {
        printf("Result return false (%d)\n", result);
        printf("I am child with pid (%d)\n", getpid());
    }

}
