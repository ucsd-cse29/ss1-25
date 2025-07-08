#include <stdio.h>
#include <assert.h>


int main(int argc, char *argv[]) {
    char a[] = {'H'};
    char *pa = a;
    printf("Indexing values: %c %c\n", a[0], pa[0]);
    printf("Dereferencing values: %c %c\n", *a, *pa);
    assert(pa[0] == 'H');

    printf("Addresses: %p %p\n", a, pa);

    // char b[] = {'C', 'S', 'E'};
    // char *ptr_b = b;
    // b[2] = 'I';
    // printf("Values: %c %c\n", b[2], ptr_b[2]);
    // printf("addresses: %p %p\n", b, ptr_b);
    // assert(b == ptr_b);
}





