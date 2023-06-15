/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stats.h>

int main(int argc, char* argv[]) {

    unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

    if (argc < 2) {
        printf("%s failed: argc=%d\n", argv[0], argc);
        return -1;
    }

    if (strcmp(argv[1], PRINT_ARRAY) == 0) {
        print_array(test, SIZE);
    } else if (strcmp(argv[1], PRINT_STATS) == 0) {
        print_statistics(test, SIZE);
    } else if (strcmp(argv[1], MEDIAN) == 0) {
        unsigned char median = find_median(test, SIZE);
        printf("The median is %u\n", median);
    } else if (strcmp(argv[1], MEAN) == 0) {
        unsigned char mean = find_median(test, SIZE);
        printf("The mean is %u\n", mean);
    } else if (strcmp(argv[1], MAXIMUM) == 0) {
        unsigned char maximum = find_median(test, SIZE);
        printf("The maximu is %u\n", maximum);
    } else if (strcmp(argv[1], MINIMUM) == 0) {
        unsigned char minimum = find_median(test, SIZE);
        printf("The minimum is %u\n", minimum);
    } else if (strcmp(argv[1], SORT) == 0) {
        sort_array(test, SIZE);
        printf("The sorted array:\n");
        print_array(test, SIZE);
    } else {
        printf("Unknown function: %s\n", argv[1]);
        return -1;
    }

    return 0;
}
