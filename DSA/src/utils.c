/*
 * utils.c
 *
 *  Created on: 03-May-2022
 *      Author: yeshasyesodharan
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

void *mem_alloc(size_t size)
{
	void *ptr = NULL;

	ptr = malloc(size);
	if(ptr != NULL)
	{
		memset(ptr, 0, size);
		return ptr;
	}

	return NULL;
}
