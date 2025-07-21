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
    char *contents = malloc(size + 1);
    strcpy(contents, init_contents);
    String r = {size, contents};
    return r;
}

String plus(String s1, String s2) {
    uint64_t new_size = s1.length + s2.length + 1;
    char *new_contents = calloc(new_size, sizeof(char));
    strncpy(new_contents, s1.contents, s1.length);
    strncpy(new_contents + s1.length, s2.contents, s2.length);
    new_contents[new_size - 1] = 0;
    String r = { new_size - 1, new_contents};
    return r;
}

String join(String strs[], int count, String delimiter) {
    String s = new_String("");
    for (int i = 0; i < count; i++) {
        char *before = s.contents;
        s = plus(s, strs[i]);
        free(before);
        if (i < count - 1) {
            char *before = s.contents;
            s = plus(s, delimiter);
            free(before);
        }
    }
    return s;
}

int main() {
    String apple = new_String("apple");
    String banana = new_String("banana");
    String strawberry = new_String("strawberry");
    String fruit[] = {apple, banana, strawberry};

    String comma = new_String(", ");
    String fruitlist = join(fruit, 3, comma);
    printf("%s\n", fruitlist.contents);
    free(apple.contents);
    free(banana.contents);
    free(strawberry.contents);
    free(fruitlist.contents);
    free(comma.contents);
}



