#ifndef __STACK_H__
#define __STACK_H__

#define STACK_SUCCESS 	0
#define STACK_FAILURE	1
typedef  void* StackData;
typedef struct __Node__
{
	StackData data;
	struct __Node__ *next;
}StackNode;

int push(StackNode **topOfStack, StackData data);
StackData pop(StackNode **topOfStack);
int stackDestroy(StackNode **topOfStack);
int stackSize(StackNode *topOfStack);
#endif
