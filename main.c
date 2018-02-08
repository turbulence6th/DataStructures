#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"
#include "queue.h"
#include "lambda.h"

int main() {
	List* list = getEmptyList();

	addToList(list, 2);
	addToList(list, 5);
	addToList(list, 10);

	printf("list: ");
	printList(list);

	removeFromList(list, 5);

	printf("list(removed 5): ");
	printList(list);

	List* reversedList = reverseFromList(list);

	printf("reversed list: ");
	printList(reversedList);

	List* copiedList = copyList(reversedList);

	printf("copied list: ");
	printList(copiedList);

	printf("first of list: %d, last of list: %d\n", getFirstFromList(list), getLastFromList(list));

	removeIfFromList(list, LAMBDA(int _(int data) {
		if (data == 2 || data == 10) {
			return 1;
		}

		return 0;
	}));

	printf("list(remove if data equals 2 or 10): ");
	printList(list);

	destroyList(list);

	destroyList(reversedList);

	destroyList(copiedList);

	Stack* stack = getEmptyStack();
	pushToStack(stack, 1);
	pushToStack(stack, 5);
	pushToStack(stack, 7);

	printf("stack: ");
	printStack(stack);
	printf("pop from stack: %d\n", popFromStack(stack));
	printf("peek from stack: %d\n", peekFromStack(stack));
	printf("stack: ");
	printStack(stack);

	destroyStack(stack);

	Queue* queue = getEmptyQueue();
	addToQueue(queue, 2);
	addToQueue(queue, 3);
	addToQueue(queue, 8);

	printf("queue: ");
	printQueue(queue);
	printf("poll from queue: %d\n", pollFromQueue(queue));
	printf("peek from queue: %d\n", peekFromQueue(queue));
	printf("queue: ");
	printQueue(queue);

	destroyQueue(queue);

}
