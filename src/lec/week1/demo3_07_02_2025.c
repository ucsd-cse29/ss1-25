#include <stdio.h>
#include <string.h>

char to_lower(char c) {
    // Given a char c, return it in lowercase
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    } else {
        return c;
    }
}

int is_ascii(char c) {
    // return 1 if c is ASCII, else return 0
    if (c >= 0 && c <= 127) {
        return 1;
    } else {
        return 0;
    }
}

int capitalize_ascii(char str[]) {
    // Return the number of characters capitalized
    // and capitalize the lowercase a-z ASCII 
    // characters of str in-place
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
            count++;
        }
    }
    return count;
}

int main() {
    // char hello[7] = "Hello";
    // char hi[2] = {'h', 'i'}; // No NULL!
    // char hi[3] = {'h', 'i', '\0'};
    // char letters2[3] = {104, 105, 0};
    // puts(hi);
    // puts(hello);
    // printf("%s\n", letters2);
    // printf("Len %s = %lu\n", letters2, strlen(letters2));

    char letter = '[';
    // printf("%c %c\n", letter, to_lower(letter));
    printf("Is ascii ? %d\n", is_ascii(letter));
    char hello[] = "Hello! ⭐";
    printf("%s\n", hello);
    int num_cap = capitalize_ascii(hello);
    printf("%s %d\n", hello, num_cap);

    return 0;
}



