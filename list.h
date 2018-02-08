#ifndef LIST_H
#define LIST_H

#include "node.h"

typedef struct List {
	int size;
	Node* head;
	Node* tail;
} List;

List* getEmptyList();
void addToList(List*, int);
void addFrontToList(List*, int);
int getSizeList(List*);
int getFirstFromList(List*);
int getLastFromList(List*);
void removeFromList(List*, int);
void removeIfFromList(List*, int (*)(int));
int getFromList(List*, int);
void addToListFromList(List*, List*);
int containsFromList(List*, int);
void forEachFromList(List*, void (*)(int));
List* copyList(List*);
List* reverseFromList(List*);
void destroyList(List*);
void printList(List*);

#endif
