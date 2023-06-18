#ifndef __DATA_H__
#define __DATA_H__

#include <inttypes.h>

#define MAX_LENGTH 34

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
