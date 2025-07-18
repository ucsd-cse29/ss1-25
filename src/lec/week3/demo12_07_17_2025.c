#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
};

typedef struct point Point;

void print_array(int *arr, uint32_t len) {
    for (int i = 0; i < len; i++) {
        printf("%d\n", arr[i]);
    }
}

Point *make_Point(int x, int y) {
    Point *p = malloc(sizeof(Point));
    p->x = x;
    p->y = y;
    return p;
}


int main(int argc, char *argv[]) {
    // User argument input
    // uint32_t len = atoi(argv[1]);
    // int *arr = malloc(len * sizeof(int));
    // // int arr[len];
    // for (int i = 0; i < len; i++) {
    //     arr[i] = i;
    // }
    // print_array(arr, len);
    // // free array
    // free(arr);

    // array of Point -- incomplete. will finish next week
    // uint32_t len = atoi(argv[1]);
    // Point **arr = malloc(len * sizeof(Point *));
}


