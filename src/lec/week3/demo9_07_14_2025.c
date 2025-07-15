#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 100

struct point {
    int x;
    int y;
};

typedef struct point Point;

Point new_point(int x, int y) {
    // struct point p;
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

double distance(Point p1, Point p2) {
   // know you have sqrt() 
   // sqrt((x1 - x2)^2 + (y1 - y2)^2)
   double x_diff = p1.x - p2.x;
   double y_diff = p1.y - p2.y;
   return sqrt(pow(x_diff, 2) + pow(y_diff, 2));

}

double distance_v2(Point *p1, Point *p2) {
    double x_diff = p1->x - p2->x;
    double y_diff = p1->y - p2->y;
    return sqrt(pow(x_diff, 2) + pow(y_diff, 2));
}

int main() {
    // struct point
    // verbose version
    // struct point p1 = new_point(0, 0);
    // struct point p2 = new_point(3, 4);
    Point p1 = new_point(0, 0);
    Point p2 = new_point(3, 4);
    printf("p1: x = %d y = %d\n", p1.x, p1.y);
    printf("p2: x = %d y = %d\n", p2.x, p2.y);
    printf("Distance(p1, p2): %f\n", distance(p1, p2));
    printf("Distance_v2(p1, p2): %f\n", distance_v2(&p1, &p2));

    // File I/O
    // FILE *input_file = fopen("in.txt", "r");
    // FILE *output_file = fopen("out.txt", "w");
    // if (input_file == NULL || output_file == NULL) {
    //     printf("Error opening files!\n");
    //     return 1;
    // }
    // int number;
    // char line[MAX_SIZE];
    // while (fgets(line, MAX_SIZE, input_file)) {
    //     // multiple num by itself
    //     // number = atoi(line);
    //     sscanf(line, "%d", &number);
    //     // printf("number read = %d\n", number);
    //     // write to out.txt this result -- probably
    //     // want to use fprintf()...
    //     fprintf(output_file, "%d\n", number * number);
    // }
    // fclose(input_file);
    // fclose(output_file);
    // return 0;
}






