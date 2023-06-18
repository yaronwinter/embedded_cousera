#ifndef __COURSE_H__
#define __COURSE_H__

#include <inttypes.h>

#define MAX_LENGTH 34

#define TEST_DATA1 "test_data1"
#define TEST_DATA2 "test_data2"
#define TEST_MEMMOVE1 "test_memmove1"
#define TEST_MEMMOVE2 "test_memmove2"
#define TEST_MEMMOVE3 "test_memmove3"
#define TEST_MEMCOPY "test_memcopy"
#define TEST_MEMSET "test_memset"
#define TEST_MEMZERO "test_memzero"
#define TEST_REVERSE "test_reverse"

int8_t course1(char * test_name);
int8_t test_data1();
int8_t test_data2();
int8_t test_memmove1();
int8_t test_memmove2();
int8_t test_memmove3();
int8_t test_memcopy();
int8_t test_memset();
int8_t test_reverse();

#endif /* __COURSE_H__ */
