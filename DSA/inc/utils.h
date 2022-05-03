#ifndef __UTILS_H__
#define __UTILS_H__

#define SIZEOF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

void delay(int number_of_seconds);
void *mem_alloc(size_t size);
#endif
