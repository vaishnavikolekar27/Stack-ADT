#include "stack_functions.h"


/*
=============== createStack ==============
This algorithm creates an empty stack.
Pre: Nothing
Post: Returns pointer to a null stack -or- NULL if overflow
*/
STACK* createStack (void)
{
	// Local Definitions
	STACK* stack;
	// Statements
	stack = (STACK*) malloc( sizeof (STACK));
	if (stack)
	{
		stack->count = 0;
		stack->top = NULL;
	}
	return stack;
} // createStack



/* ================= emptyStack ================
This function determines if a stack is empty.
Pre stack is pointer to a stack
Post returns 1 if empty; 0 if data in stack
*/
bool emptyStack(STACK* stack)
{
	return(stack->count == 0);
}//emptyStack



/* ================== fullStack =================
This function determines if a stack is full.
Full is defined as heap full.
Pre: stack is pointer to a stack head node
Return true if heap full
false if heap has room
*/
bool fullStack(STACK* stack)
{
	STACK_NODE *temp;
	if((temp = (STACK_NODE *)malloc(sizeof(STACK_NODE))))
	{
		free (temp);
		return false;
	}
    	return true;
}//fullStack



/* ================== stackCount =================
Returns number of elements in stack.
Pre: stack is a pointer to the stack
Post: count returned
*/
int stackCount(STACK* stack)
{

	return stack->count;

}//stckCount



/*
================= pushStack ================
This function pushes an item onto the stack.
Pre: stack is a pointer to the stack dataPtr pointer to data to be inserted
Post: Data inserted into stack Return true if successful false if underflow
*/
bool pushStack (STACK* stack, STACK_NODE *dataInPtr)
{
	if(fullStack(stack))
		return false;

	STACK_NODE* tmp;
	tmp = (STACK_NODE* ) malloc(sizeof( STACK_NODE));
	tmp->dataPtr = dataInPtr->dataPtr;
	tmp->link = stack->top;
	stack->top = tmp;
	(stack->count)++;
	return true;
}// pushStack



/* =================== popStack ==================
This function pops item on the top of the stack.
Pre: stack is pointer to a stack
Post: Returns pointer to user data if successful NULL if underflow
*/
void *popStack(STACK *stack)
{
	void *dataOutPtr;
	STACK_NODE *tmp;
	if(stack->count==0)
		dataOutPtr=NULL;
	else
	{
		tmp=stack->top;
		dataOutPtr=stack->top->dataPtr;
		stack->top=stack->top->link;
		free(tmp);
		(stack->count)--;
	}//else
	return dataOutPtr;
}//Popstack



/* ================== stackTop =================
Retrieves data from the top of stack without changing the stack.
Pre: stack is a pointer to the stack
Post: Returns data pointer if successful
null pointer if stack empty
*/
void* stackTop(STACK *stack)
{
	//Statements
	if(stack->count == 0)
		return NULL;
	else
		return (stack->top->dataPtr);
}//stackTop



/* ================== displayStack =================
This function displays all nodes of the stack.
Pre: A stack
Post: Displays all the nodes
*/
void displayStack(STACK *stack)
{
	if(stack->count==0)
	{
		printf("\nStack is empty\n");
		return;
	}
	STACK_NODE *tmptop = stack->top;
	printf("\nItems in the stack are\n");
	while(tmptop != NULL)
	{
		printf("\n%s",(char*)tmptop->dataPtr);
		tmptop = tmptop->link;
	}
	printf("\n");

}//displayStack



/* ================== destroyStack =================
This function releases all nodes to the heap.
Pre: A stack
Post: returns null pointer
*/
STACK* destroyStack(STACK* stack)
{
	STACK_NODE* tmp;
	if(stack)
	{
		while(stack->top != NULL)
		{
			free(stack->top->dataPtr);
			tmp = stack->top;
			stack->top = stack->top->link;
			free(tmp);
		}
	free(stack);
	}
	return NULL;
}//destoryStack
