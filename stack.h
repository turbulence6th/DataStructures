#ifndef STACK_H
#define STACK_H

#include "list.h"

typedef struct Stack {
	List* list;
} Stack;

Stack* getEmptyStack();
void pushToStack(Stack*, int);
int peekFromStack(Stack*);
int popFromStack(Stack*);
int getSizeStack(Stack*);
void printStack(Stack*);
void destroyStack(Stack*);

#endif
