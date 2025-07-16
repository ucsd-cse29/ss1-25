#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

struct string {
    uint64_t length; // strlen(contents)
    char *contents; // space for length + null terminator
};

typedef struct string String;

String new_String(char *init_contents) {
    uint64_t size = strlen(init_contents);
    String r = {size, init_contents};
    return r;
}

// BAD version of plus!!! only stack-allocated new_contents array
// String plus(String s1, String s2) {
//     uint64_t new_size = s1.length + s2.length + 1;
//     char new_contents[new_size];
//     strncpy(new_contents, s1.contents, s1.length);
//     strncpy(new_contents + s1.length, s2.contents, s2.length);
//     new_contents[new_size] = 0;
//     String r = { new_size - 1, new_contents};
//     return r;
// }

String plus(String s1, String s2) {
    uint64_t new_size = s1.length + s2.length + 1;
    char *new_contents = calloc(new_size, sizeof(char));
    strncpy(new_contents, s1.contents, s1.length);
    strncpy(new_contents + s1.length, s2.contents, s2.length);
    new_contents[new_size - 1] = 0;
    String r = { new_size - 1, new_contents};
    return r;
}

int main() {
    String s = new_String("hello"); 
    printf("%s\n", s.contents);
    String s2 = new_String("cse29");
    String hello_cse = plus(s, s2);
    printf("%s\n", hello_cse.contents);
    String hello_bang = plus(s, new_String("!!!!"));
    printf("%s\n", hello_cse.contents);
    printf("%s\n", hello_bang.contents);
    free(hello_cse.contents);
    free(hello_bang.contents);
}



