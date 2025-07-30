#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/mman.h>

#define HEAP_SIZE 400
#define CHUNK_SIZE 8

uint64_t *HEAP_START = NULL;

void init_heap() {
    // Hey OS, where can I start my heap?
    uint64_t *heap = mmap(
        NULL,
        HEAP_SIZE,
        PROT_READ | PROT_WRITE,
        MAP_ANON | MAP_SHARED,
        -1,
        0
    );
    HEAP_START = heap;
    // header
    *HEAP_START = HEAP_SIZE;    
}

void *my_malloc(size_t size) {
    uint64_t *current = HEAP_START;
    while (current < (HEAP_START + (HEAP_SIZE / CHUNK_SIZE))) {
        // Traverse the heap
        uint64_t cur_header = *current; // reading the header
        uint64_t cur_size = cur_header & (~1); // get size
        uint64_t is_free = ~cur_header & 1;
        if(is_free && (size + sizeof(uint64_t) <= cur_size)) {
            // Proceed
            // Split the block into malloc'd and free parts if needed
            // Round up size to the next multiple of 8
            size_t size_w_hdr = size + sizeof(uint64_t);
            size_t rounded = ((size_w_hdr + 7) / 8) * 8;
            // check if we need to split or not 
            if (cur_size > rounded + 8) { // +8 so no dangling 8-byte chunks
                *current = rounded + 1; // set the alloc'd bit
                //split
                uint64_t *remaining = current + (*current / 8);
                *remaining = cur_size - rounded;
            } else {
                *current += 1;
            }
            return current + 1;
        } else { //not in a free block
            // go to the next block
            uint64_t *next = current + (cur_size / 8);
            current = next;
        }
    }
    return NULL;
}

void my_free(void *p) {
    // how do I free p?
    uint64_t *current = p;
    uint64_t *header = current - 1;
    if(*header & 1 == 1) {
        *header = *header & ~1;
    }
}


void print_heap() {
    uint64_t *current = HEAP_START;
    while (current < (HEAP_START + (HEAP_SIZE / CHUNK_SIZE))) {
        uint64_t cur_header = *current;
        uint64_t cur_size = (cur_header / 2) * 2;
        printf("%p\t%ld\t%ld\n", current, cur_header % 2, cur_size);
        uint64_t *next = current + (cur_size / CHUNK_SIZE);
        current = next;
    }
    printf("\n\n");
}

int main() {
    init_heap();
    // size_t size = 48;
    // size_t size_w_hdr = size + sizeof(uint64_t);
    // size_t rounded1 = ((size_w_hdr + 7) / 8) * 8;
    // size_t rounded2 = (size_w_hdr + 7) & (~0x7);
    // size_t rounded3 = (size_w_hdr % 8 == 0) ? size_w_hdr : (8 - (size_w_hdr % 8)) + size_w_hdr;

    // printf("rounded1 = %ld\n", rounded1);
    // printf("rounded2 = %ld\n", rounded2);
    // printf("rounded3 = %ld\n", rounded3);

    int *a = my_malloc(40);
    int *b = my_malloc(10);
    int *c = my_malloc(20);
    my_free(a);
    my_free(b);
    print_heap();
}






