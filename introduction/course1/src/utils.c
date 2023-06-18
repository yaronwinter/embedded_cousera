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
#ifdef VERBOSE
    printf("Array:");
    for (int i = 0; i < length; i++) {
        printf("\tarray[%d] = %u\n", i, array[i]);
    }
#endif
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
