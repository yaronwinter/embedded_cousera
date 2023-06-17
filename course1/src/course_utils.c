#include <course.h>
#include <platform.h>
#include <data.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int8_t test_data1() {
    uint8_t * str1 = (uint8_t *)"1234";
    uint8_t * str2 = (uint8_t *)"-1234";
    uint8_t * str3 = (uint8_t *)"01100101";
    uint8_t * str4 = (uint8_t *)"0FC03";
    uint8_t * str5 = (uint8_t *)"-0FC03";
    PRINTF("%s -> %d\n", str1, my_atoi(str1, 4, 10));
    PRINTF("%s -> %d\n", str2, my_atoi(str2, 4, 10));
    PRINTF("%s -> %d\n", str3, my_atoi(str3, 8, 2));
    PRINTF("%s -> %d\n", str4, my_atoi(str4, 5, 16));
    PRINTF("%s -> %d\n", str5, my_atoi(str5, 5, 16));
    return 0;
}

int8_t test_data2() {
    uint8_t buffer[MAX_LENGTH];
    uint8_t length = my_itoa(1234, buffer, 10);
    PRINTF("1234 on decimal : length=%d, str=%s\n", length, buffer);

    length = my_itoa(1234, buffer, 2);
    PRINTF("1234 on binary : length=%d, str=%s\n", length, buffer);

    length = my_itoa(1234, buffer, 16);
    PRINTF("1234 on hex : length=%d, str=%s\n", length, buffer);

    length = my_itoa(-64515, buffer, 2);
    PRINTF("-64515 on binary : length=%d, str=%s\n", length, buffer);

    length = my_itoa(-64515, buffer, 10);
    PRINTF("-64515 on decimal : length=%d, str=%s\n", length, buffer);

    length = my_itoa(-64515, buffer, 16);
    PRINTF("-64515 on hex : length=%d, str=%s\n", length, buffer);

    return 0;
}

int8_t test_memmove1() {
    uint8_t * src = (uint8_t*)malloc(13*sizeof(uint8_t));
    uint8_t * dst = (uint8_t*)malloc(18*sizeof(uint8_t));

    dst = (uint8_t*)strcpy((char*)dst, "winter all family");
    src = (uint8_t*)strcpy((char*)src, "yaron winter");

    PRINTF("Original Src = %s\n", src);
    PRINTF("Original Dst = %s\n", dst);

    uint8_t * res = my_memmove(src, dst, 12);
    PRINTF("Res = %s\n", res);

    free(src);
    free(dst);
    return 0;
}

int8_t test_memmove2() {
    uint8_t * buffer = (uint8_t*)malloc(40*sizeof(uint8_t));
    buffer = (uint8_t*)strcpy((char*)buffer, "winter all family together with sadans");

    uint8_t * dst = buffer;
    uint8_t * src = buffer + 18;

    PRINTF("Original Src = %s\n", src);
    PRINTF("Original Dst = %s\n", dst);
    PRINTF("Copy Len = 20\n");

    uint8_t * res = my_memmove(src, dst, 20);

    PRINTF("Res: %s\n", res);
    free(buffer);
    return 0;
}

int8_t test_memmove3() {
    uint8_t * buffer = (uint8_t*)malloc(40*sizeof(uint8_t));
    buffer = (uint8_t*)strcpy((char*)buffer, "winter all family together with sadans");

    uint8_t * src = buffer;
    uint8_t * dst = buffer + 17;
    PRINTF("Original Src = %s\n", src);
    PRINTF("Original Dst = %s\n", dst);
    PRINTF("Copy Len = 20\n");

    uint8_t * res = my_memmove(src, dst, 20);
    PRINTF("Res = %s\n", res);
    free(buffer);
    return 0;
}

int8_t test_memcopy() {
    uint8_t * src = (uint8_t*)malloc(13*sizeof(uint8_t));
    uint8_t * dst = (uint8_t*)malloc(18*sizeof(uint8_t));

    dst = (uint8_t*)strcpy((char*)dst, "winter all family");
    src = (uint8_t*)strcpy((char*)src, "yaron winter");

    PRINTF("Original Src = %s\n", src);
    PRINTF("Original Dst = %s\n", dst);
    PRINTF("Copy Len = 12\n");

    uint8_t * res = my_memcopy(src, dst, 12);
    PRINTF("No Overlap: %s\n", res);
    free(src);
    free(dst);

    uint8_t * buffer = (uint8_t*)malloc(40*sizeof(uint8_t));
    buffer = (uint8_t*)strcpy((char*)buffer, "winter all family together with sadans");

    dst = buffer;
    src = buffer + 18;

    PRINTF("Original Src = %s\n", src);
    PRINTF("Original Dst = %s\n", dst);
    PRINTF("Copy Len = 20\n");


    res = my_memcopy(src, dst, 20);
    PRINTF("Overlap at Start Dest: %s\n", res);

    buffer = (uint8_t*)strcpy((char*)buffer, "winter all family together with sadans");
    dst = buffer + 17;
    src = buffer;
    
    PRINTF("Original Src = %s\n", src);
    PRINTF("Original Dst = %s\n", dst);
    PRINTF("Copy Len = 20\n");


    res = my_memcopy(src, dst, 20);
    PRINTF("Overlap at Start Src: %s\n", res);

    free(buffer);
    return 0;
}

int8_t test_memset() {
    uint8_t buffer[MAX_LENGTH];
    PRINTF("Set Val F: %s\n", my_memset(buffer, 10, 'F'));
    PRINTF("Set Zero: %s\n", my_memzero(buffer, 10));
    return 0;
}

int8_t test_reverse() {
    uint8_t * buffer = (uint8_t *)malloc(13*sizeof(uint8_t));
    buffer = (uint8_t*)strcpy((char*)buffer, "yaron winter");
    PRINTF("Reverse string: %s\n", buffer);
    PRINTF("Reversed: %s\n", my_reverse(buffer, 12));
    return 0;
}
