/*
 * queue.c
 *
 *  Created on: 03-May-2022
 *      Author: yeshasyesodharan
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "queue.h"
#include "utils.h"

/**
 * @fn int enqueueSQ(SimpleQueue**, QueueData)
 * @brief
 *
 * @pre
 * @post
 * @param queue
 * @param data
 * @return
 */
int enqueueSQ(SimpleQueue **queue, QueueData data)
{
	SimpleQueue *ptrQueue;;
	QueueNode *newNode = NULL;

	if(queue == NULL)
	{
		return QUEUE_FAILURE;
	}


	if(*queue == NULL)
	{
		*queue = (SimpleQueue *) mem_alloc(sizeof(SimpleQueue));

	}

	ptrQueue = *queue;

	if(ptrQueue->front == NULL)
	{
		newNode = (QueueNode *) mem_alloc(sizeof(QueueNode));
		newNode->data = data;
		newNode->next = NULL;

		ptrQueue->rear = newNode;
		ptrQueue->front = newNode;
		ptrQueue->rear->next = NULL;
		ptrQueue->front->next = NULL;
		ptrQueue->size++;

	}
	else
	{
		newNode = (QueueNode *) mem_alloc(sizeof(QueueNode));
		newNode->data = data;
		newNode->next = NULL;

		ptrQueue->rear->next = newNode;
		ptrQueue->rear = ptrQueue->rear->next;
		ptrQueue->size++;
	}

	return QUEUE_SUCCESS;
}

/**
 * @fn QueueData dequeueSQ(SimpleQueue**)
 * @brief
 *
 * @pre
 * @post
 * @param queue
 * @return
 */
QueueData dequeueSQ(SimpleQueue **queue)
{
	SimpleQueue *ptrQueue;;
	QueueNode *tempNode = NULL;
	QueueData data = NULL;

	if(queue == NULL || *queue == NULL)
	{
		return NULL;
	}

	ptrQueue = *queue;

	if(ptrQueue->front != NULL)
	{
		tempNode = ptrQueue->front;
		ptrQueue->front = tempNode->next;

		data = tempNode->data;
		free(tempNode);
		ptrQueue->size--;
	}

	return data;
}

/**
 * @fn int lengthSQ(SimpleQueue*)
 * @brief
 *
 * @pre
 * @post
 * @param queue
 * @return
 */
int lengthSQ(SimpleQueue *queue)
{
	if(queue == NULL)
	{
		return 0;
	}

	return queue->size;
}
