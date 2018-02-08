#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "lambda.h"

List* getEmptyList() {
	List* list = malloc(sizeof(List));
	list->size = 0;
	list->head = malloc(sizeof(Node));
	list->tail = list->head;
	return list;
}

void addToList(List* list, int data) {
	Node* node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	list->tail->next = node;
	list->tail = node;
	list->size++;
}

void addFrontToList(List* list, int data) {
	Node* node = malloc(sizeof(Node));
	node->data = data;
	node->next = list->head->next;
	list->head->next = node;
	if (list->tail == list->head) {
		list->tail = node;
	}

	list->size++;
}

int getSizeList(List* list) {
	return list->size;
}

int getFirstFromList(List* list) {
	if (list->size == 0) {
		exit(EXIT_FAILURE);
	}

	return list->head->next->data;
}

int getLastFromList(List* list) {
	if (list->size == 0) {
		exit(EXIT_FAILURE);
	}

	return list->tail->data;
}

void removeFromList(List* list, int data) {
	for (Node* temp = list->head; temp->next != NULL; temp = temp->next) {
		Node* next = temp->next;
		if (next->data == data) {
			temp->next = next->next;
			free(next);
			list->size--;
		}
	}
}

void removeIfFromList(List* list, int (*f)(int)) {
	for (Node* temp = list->head; temp->next != NULL; temp = temp->next) {
		Node* next = temp->next;
		if ((*f)(next->data)) {
			temp->next = next->next;
			free(next);
			list->size--;
		}
	}
}

int getFromList(List* list, int index) {
	Node* temp = list->head->next;
	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}

	return temp->data;
}

void addToListFromList(List* list1, List* list2) {
	forEachFromList(list2, LAMBDA(void _(int data) {
		addToList(list1, data);
	}));
}

int containsFromList(List* list, int data) {
	for (Node* temp = list->head->next; temp != NULL; temp = temp->next) {
		if (temp->data == data) {
			return 1;
		}
	}

	return 0;
}

void forEachFromList(List* list, void (*f)(int)) {
	for (Node* temp = list->head->next; temp != NULL; temp = temp->next) {
		(*f)(temp->data);
	}
}

List* copyList(List* list) {
	List* newList = getEmptyList();

	forEachFromList(list, LAMBDA(void _(int data) {
		addToList(newList, data);
	}));

	return newList;
}

List* reverseFromList(List* list) {
	List* newList = getEmptyList();

	forEachFromList(list, LAMBDA(void _(int data) {
		addFrontToList(newList, data);
	}));

	return newList;
}

void destroyList(List* list) {
	for (Node* temp = list->head; temp->next != NULL;) {
		Node* next = temp->next;
		temp->next = next->next;
		free(next);
	}

	free(list->head);
	free(list);
}

void printList(List* list) {
	forEachFromList(list, LAMBDA(void _(int data) {
		printf("%d ", data);
	}));

	printf("\n");
}
