#ifndef __QUEUE_H__
#define __QUEUE_H__

#define QUEUE_SUCCESS 	0
#define QUEUE_FAILURE	1

typedef  void* QueueData;
typedef struct __QueueNode__
{
	QueueData data;
	struct __QueueNode__ *next;
}QueueNode;

typedef struct
{
	QueueNode *front;
	QueueNode *rear;
	int size;
}SimpleQueue;

int enqueueSQ(SimpleQueue **queue, QueueData data);
QueueData dequeueSQ(SimpleQueue **queue);
int lengthSQ(SimpleQueue *queue);

#endif
