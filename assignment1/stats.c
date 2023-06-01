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

/* Size of the Data Set */
#define SIZE (40)

#define PRINT_ARRAY "print_array"
#define PRINT_STATS "print_stats"
#define MEDIAN "median"
#define MAXIMUM "maximum"
#define MINIMUM "minimum"
#define MEAN "mean"
#define SORT "sort"

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

void print_statistics(unsigned char* array, int length) {
    printf("The orginal array:\n");
    print_array(array, length);

    sort_array(array, length);
    printf("\nSorted array:\n");
    print_array(array, length);
    
    printf("\nMedian = %u\n", find_median(array, length));
    printf("Mean = %u\n", find_mean(array, length));
    printf("Maximum = %u\n", find_maximum(array, length));
    printf("Minimum = %u\n", find_minimum(array, length));
}

void print_array(unsigned char* array, int length) {
    printf("Array:");
    for (int i = 0; i < length; i++) {
        printf("\tarray[%d] = %u\n", i, array[i]);
    }
}

unsigned char find_median(unsigned char* array, int length) {
    qsort(array, length, sizeof(unsigned char), comp_func);
    if (length % 2 == 0) {
        int mid_index = length / 2;
        return (unsigned char)((array[mid_index] + array[mid_index + 1]) / 2);
    }

    return (array[(length + 1) / 2]);
}

unsigned char find_mean(unsigned char* array, int length) {
    unsigned int total_sum = 0;
    for (int i = 0; i < length; i++) {
        total_sum += array[i];
    }
    return (unsigned char)(total_sum / length);
}

unsigned char find_maximum(unsigned char* array, int length) {
    unsigned char max_val = 0;
    for (int i = 0; i < length; i++) {
        unsigned char curr_val = array[i];
        if ((curr_val > max_val) || (i == 0)) {
            max_val = curr_val;
        }
    }
    return max_val;
}

unsigned char find_minimum(unsigned char* array, int length) {
    unsigned char min_val = 0;
    for (int i = 0; i < length; i++) {
        unsigned char curr_val = array[i];
        if ((curr_val < min_val) || (i == 0)) {
            min_val = curr_val;
        }
    }
    return min_val;
}

void sort_array(unsigned char* array, int length) {
    qsort(array, length, sizeof(unsigned char), comp_func);
}

int comp_func(const void * a, const void * b) {
    return ( *(unsigned char*)b - *(unsigned char*)a );
}
