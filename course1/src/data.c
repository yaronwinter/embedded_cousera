#include <data.h>
#include <memory.h>

#define DIGITS "0123456789ABCDEF"

uint8_t my_itoa(int32_t data, uint8_t * buffer, uint32_t base) {
    //printf("enter my_itoa\n");
    buffer = my_memzero(buffer, MAX_LENGTH);

    //printf("handle sign\n");
    int sign = 0;
    int32_t val = data;
    if (data < 0) {
        sign = 1;
        val = -data;
    }

    //printf("start loop. sign = %d, val = %d\n", sign, val);
    uint8_t * piv = buffer;
    int length = 0;
    while ((val > 0) || (piv == buffer)) {
        int32_t digit = val % base;
        val /= base;

        *piv++ = DIGITS[digit];
        length++;
    }
    //printf("end loop. len=%d, piv=%d, buffer=%s\n", length, (int)(piv-buffer), buffer);

    if (sign > 0) {
        *piv++ = '-';
        length++;
    }

    //printf("start reverse. len=%d, buffer=%s\n", length, buffer);
    buffer = my_reverse(buffer, length);
    buffer[length] = 0;
    length++;
    //printf("exit my_itoa: len=%d, buffer=%s\n", length, buffer);
    return length;
}

int32_t my_atoi(uint8_t * buffer, uint8_t digits, uint32_t base) {
    int32_t value = 0;
    const int32_t sign = (*buffer == '-' ? -1 : 1);
    uint8_t * piv = buffer + digits - (sign == 1 ? 1 : 0);

    int32_t factor = 1;
    for (int i = 0; i < digits; i++) {
        uint8_t c = *piv--;
        int32_t digit = ((c - '0') < 10 ? c - '0' : c - 'A' + 10);
        value += digit * factor;
        factor *= base;
    }
     
    return sign * value;
}
