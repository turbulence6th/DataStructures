#include <stdlib.h>
#include "stack.h"

Stack* getEmptyStack() {
	Stack* stack = malloc(sizeof(Stack));
	stack->list = getEmptyList();
	return stack;
}

void pushToStack(Stack* stack, int data) {
	addFrontToList(stack->list, data);
}

int peekFromStack(Stack* stack) {
	return getFirstFromList(stack->list);
}

int popFromStack(Stack* stack) {
	if (stack->list->size == 0) {
		exit(EXIT_FAILURE);
	}

	Node* next = stack->list->head->next;
	int data = next->data;
	stack->list->head->next = next->next;
	free(next);
	stack->list->size--;
	return data;
}

int getSizeStack(Stack* stack) {
	return stack->list->size;
}

void printStack(Stack* stack) {
	printList(stack->list);
}

void destroyStack(Stack* stack) {
	destroyList(stack->list);
	free(stack);
}
