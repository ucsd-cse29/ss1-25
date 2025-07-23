#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
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

struct List {
    uint32_t size;
    uint32_t capacity;
    String *contents;
};

typedef struct List List;

// void append_bad(List a, String value) {
//     // a.size == a.capacity?? need to expand
//     a.contents[a.size] = value;
//     a.size += 1;
// }

List new_List() {
    List a = {0, 10, calloc(10, sizeof(String))};
    return a;
}

void expand_capacity(List *a) {
    // Double capacity 
    uint32_t new_cap = a->capacity * 2;
    String *new_ptr = realloc(a->contents, new_cap * sizeof(String));
    a->capacity = new_cap;
    a->contents = new_ptr;
}

void append1(List *a, String value) {
    if (a->size + 1 == a->capacity) {
        expand_capacity(a);
    }
    a->contents[a->size] = value;
    a->size += 1;
}


void destroy_List(List *a) {
    // free contents of each element (String) 
    // free contents of List
    for (int i = 0; i < a->size; i++) {
        free(a->contents[i].contents);
    }
    free(a->contents);
}


int main() {

    List a = new_List();
    append1(&a, new_String("apple"));
    append1(&a, new_String("banana"));
    append1(&a, new_String("cranberry"));

    for (int i = 0; i < a.size; i++) {
        printf("%s\n", a.contents[i].contents);
    }
    destroy_List(&a);
}








