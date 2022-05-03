/*
 * stack.c
 *
 *  Created on: 29-Apr-2022
 *      Author: yeshasyesodharan
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "stack.h"

/**
 * @fn int push(StackNode*, StackData)
 * @brief
 *
 * @pre
 * @post
 * @param topOfStack
 * @param data
 * @return
 */
int push(StackNode **topOfStack, StackData data)
{
	StackNode *top;

	top = (StackNode *) malloc(sizeof(StackNode));
	memset(top, 0, sizeof(StackNode));
	top->data = data;
	top->next = *topOfStack;

	*topOfStack = top;

	return STACK_SUCCESS;

}

/**
 * @fn StackData pop(StackNode*)
 * @brief
 *
 * @pre
 * @post
 * @param topOfStack
 * @return
 */
StackData pop(StackNode **topOfStack)
{
	StackNode *top;
	StackData data;

	top = *topOfStack;
	if(top == NULL)
	{
		return NULL;
	}

	top = *topOfStack;
	*topOfStack = top->next;
	data = top->data;
	free(top);

	return data;
}

/**
 * @fn int stackDestroy(StackNode*)
 * @brief
 *
 * @pre
 * @post
 * @param topOfStack
 * @return
 */
int stackDestroy(StackNode **topOfStack)
{
	StackNode *top, *temp;

	top = *topOfStack;

	if(top == NULL) return STACK_FAILURE;

	while(top != NULL)
	{
		temp = top;
		top = temp->next;
		free(temp);
	}

	*topOfStack = NULL;

	return STACK_SUCCESS;
}

/**
 * @fn int stackSize(StackNode*)
 * @brief
 *
 * @pre
 * @post
 * @param topOfStack
 * @return
 */
int stackSize(StackNode *topOfStack)
{
	StackNode *top;
	int size = 0;

	top = topOfStack;

	while(top != NULL)
	{
		size++;
		top = top->next;
	}

	return size;
}
