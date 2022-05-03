/*
 ============================================================================
 Name        : DSA.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "stack.h"
#include "utils.h"
int TEST_STACK(void)
{
	StackNode *topOfStack = NULL;
	StackData data = NULL;
	uint32_t inputData[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
	int testCase = 1;
	char popString[] = "Popped Value: %d\n";
	char pushString[] = "Pushed Value: %d\n";
	char printString[100] = "";
	volatile int testLoop = 1;
	puts("Executing test case for STACK\n");

	while(testLoop)
	{
		switch(testCase)
		{
		case 0:
			testLoop = 0;
			break;

		case 1:

				for(int i = 0; i < (SIZEOF_ARRAY(inputData)); i++)
				{
					data = (StackData *)malloc(sizeof(uint32_t));
					memset(data, 0, sizeof(uint32_t));
					memcpy(data, &inputData[i], sizeof(uint32_t));

					if(STACK_SUCCESS != push(&topOfStack, data))
					{
						puts("PUSH Failed");
						fflush(stdout);
					}

					snprintf(printString,  sizeof(pushString), &pushString[0], *(uint32_t *)data);
					puts(printString);
					fflush(stdout);
					delay(1);
				}
				testCase = 2;
			break;

		case 2:
			for(int i = sizeof(inputData) - 1; i >= 0 ; i--)
			{
				data = pop(&topOfStack);
				if(data == NULL)
				{
					puts("Nothing to POP\n");
					testCase = 0xFF;
				}

				snprintf(printString,  sizeof(printString), &popString[0], *(uint32_t *)data);
				puts(printString);
				fflush(stdout);
				delay(1);
			}
			testCase = 0;
			break;

		case 3:
			break;

		case 4:
			break;

		case 5:
			break;
		default:
			//puts("Invalid test case\n");
			break;
		}
	}
}
int main(void) {

	TEST_STACK();
	return EXIT_SUCCESS;
}
