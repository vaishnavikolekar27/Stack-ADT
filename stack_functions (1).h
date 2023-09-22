#ifndef STACK_FUNCTIONS_H
#define STACK_FUNCTIONS_H
#include "stdbool.h"
#include "stdlib.h"
#include "stdio.h"
#include "ctype.h"

// Stack ADT Type Defintions
typedef struct node
{
	void* dataPtr;
	struct node* link;
}STACK_NODE;
typedef struct
{
	int count;
	STACK_NODE* top;
}STACK;


STACK* createStack(void);
bool emptyStack(STACK*);
bool fullStack(STACK*);
int stackCount(STACK*);
bool pushStack(STACK*, STACK_NODE*);
void* popStack(STACK*);
void* stackTop(STACK*);
void displayStack(STACK*);
STACK* destroyStack(STACK*);

#endif
