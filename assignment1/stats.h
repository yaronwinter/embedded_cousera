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
#ifndef __STATS_H__
#define __STATS_H__

int comp_func(const void * a, const void * b);
void print_statistics(unsigned char* array, int length);
void print_array(unsigned char* array, int length);
unsigned char find_median(unsigned char* array, int length);
unsigned char find_mean(unsigned char* array, int length);
unsigned char find_maximum(unsigned char* array, int length);
unsigned char find_minimum(unsigned char* array, int length);
void sort_array(unsigned char* array, int length);

#endif //__STATS_H__