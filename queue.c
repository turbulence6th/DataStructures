#include <stdlib.h>
#include "queue.h"

Queue* getEmptyQueue() {
	Queue* queue = malloc(sizeof(Queue));
	queue->list = getEmptyList();
	return queue;
}

void addToQueue(Queue* queue, int data) {
	addToList(queue->list, data);
}

int peekFromQueue(Queue* queue) {
	return getFirstFromList(queue->list);
}

int pollFromQueue(Queue* queue) {
	if (queue->list->size == 0) {
		exit(EXIT_FAILURE);
	}

	Node* next = queue->list->head->next;
	int data = next->data;
	queue->list->head->next = next->next;
	free(next);
	queue->list->size--;
	return data;
}

int getSizeQueue(Queue* queue) {
	return queue->list->size;
}

void printQueue(Queue* queue) {
	printList(queue->list);
}

void destroyQueue(Queue* queue) {
	destroyList(queue->list);
	free(queue);
}
