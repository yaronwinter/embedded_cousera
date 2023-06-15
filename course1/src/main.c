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
/**
 * @file main.c
 * @brief Main entry point to the C1M2 Assessment
 *
 * This file contains the main code for the C1M2 assesment. Students
 * are not to change any of the code, they are instead supposed to compile
 * these files with their makefile.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include <platform.h>
#include <memory.h>

#define MAX_LENGTH (10)
char buffer[MAX_LENGTH];

/* A pretty boring main file */
int main(void) {
  char c;
  int i;
  char * pc;
  int * pi;
  long int li;
  long long int lli;

  PRINTF("sizeof(char) = %lu\n", sizeof(c));
  PRINTF("sizeof(int) = %lu\n", sizeof(i));
  PRINTF("sizeof(char*) = %lu\n", sizeof(pc));
  PRINTF("sizeof(int*) = %lu\n", sizeof(pi));
  PRINTF("sizeof(long int) = %lu\n", sizeof(li));
  PRINTF("sizeof(long long int) = %lu\n", sizeof(lli));


  char * s = &buffer[0];
  PRINTF("Array first entry: %ld (%p)\n", (long int)s, s);

  char * e = &buffer[MAX_LENGTH];
  PRINTF("Array last entry: %ld (%p)\n", (long int)e, e);

  PRINTF("#items = %ld\n", ((long int)e - (long int)s));

  s++;
  PRINTF("Second Entry =  %ld (%p)\n", (long int)s, s);

  s++;
  PRINTF("Third Entry =  %ld (%p)\n", (long int)s, s);

  s++;
  PRINTF("Fourth Entry =  %ld (%p)\n", (long int)s, s);
  return 0;
}
