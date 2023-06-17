#include <course.h>
#include <platform.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
#ifdef COURSE1
    if (argc < 2) {
        printf("%s failed: argc=%d\n", argv[0], argc);
        return -1;
    }

    return course1(argv[1]);
#endif

    PRINTF("Do nothing...\n");
    return 0;
}

int8_t course1(char * test_name) {
    if (strcmp(test_name, TEST_DATA1) == 0) {
        test_data1();
    } else if (strcmp(test_name, TEST_DATA2) == 0) {
        test_data2();
    } else if (strcmp(test_name, TEST_MEMMOVE1) == 0) {
        test_memmove1();
    } else if (strcmp(test_name, TEST_MEMMOVE2) == 0) {
        test_memmove2();
    } else if (strcmp(test_name, TEST_MEMMOVE3) == 0) {
        test_memmove3();
    } else if (strcmp(test_name, TEST_MEMCOPY) == 0) {
        test_memcopy();
    } else if (strcmp(test_name, TEST_MEMSET) == 0) {
        test_memset();
    } else if (strcmp(test_name, TEST_REVERSE) == 0) {
        test_reverse();
    } else {
        printf("Unknown function: %s\n", test_name);
        return -1;
    }
    return 0;
}
