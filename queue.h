#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

typedef struct Queue {
	List* list;
} Queue;

Queue* getEmptyQueue();
void addToQueue(Queue*, int);
int peekFromQueue(Queue*);
int pollFromQueue(Queue*);
int getSizeQueue(Queue*);
void printQueue(Queue*);
void destroyQueue(Queue*);

#endif
