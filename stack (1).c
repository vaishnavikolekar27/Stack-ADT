 #include "stack_functions.h"

STACK *stack = NULL;
STACK_NODE *item = NULL;

int main(int argc, char* argv[])
{
	int ch,temp;
	char *anyval;
	bool tmp;
	void *data;
	while(1)
	{
		printf("\n======================");
		printf("\n1.Create Stack");
		printf("\n2.Push Element");
		printf("\n3.Pop Stack");
		printf("\n4.Stack Count");
		printf("\n5.Top Element");
		printf("\n6.Check Empty Stack");
		printf("\n7.Check Full Stack");
		printf("\n8.Display Stack");
		printf("\n9.Destory Stack");
		printf("\n10.Exit");
		printf("\nChoose: ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1: if(stack == NULL)
				{
					stack = createStack();	/*Stack is created*/
					printf("\nStack is created\n");
				}
				else
					printf("\nStack already exists\n");
				break;

			case 2: if(stack != NULL)
				{
					printf("\nEnter the item to be pushed: ");
					anyval = (char*)malloc(sizeof(20));
					item = (STACK_NODE*)malloc(sizeof(STACK_NODE));
					scanf("%s", anyval);
					item->dataPtr = anyval;
					if(pushStack(stack,item))
						printf("\nPushed %s\n",(char*)item->dataPtr);
					else
						printf("\nStack Overflow\n");
				}
				else
					printf("\nStack not created\n");
				break;

			case 3: if(stack != NULL)
				{
					data = popStack(stack);
					if(data)
						printf("\nItem popped: %s\n", (char*)data);
					else
						printf("\nStack underflow\n");
				}
				else
					printf("\nStack not created\n");
				break;

			case 4: if(stack != NULL)
				{
					temp = stackCount(stack);
					printf("\nStack count: %d\n", temp);
				}
				else
					printf("\nStack not created\n");
				break;

			case 5: if(stack != NULL)
				{
					data = stackTop(stack);
					if(data)
						printf("\nTop of stack: %s\n", (char*)data);
					else
						printf("\nStack underflow, stackTop is empty\n");
				}
				else
					printf("\nStack not created\n");
				break;
			case 6:	if(stack != NULL)
				{
					tmp = emptyStack(stack);
					if(tmp)
						printf("\nStack is empty\n");
					else
						printf("\nStack is not empty\n");
				}
				else
					printf("\nStack not created\n");
				break;
			case 7: if(stack != NULL)
				{
					tmp = fullStack(stack);
					if(!tmp)
						printf("\nStack is not full\n");
					else
						printf("\nStack Overflow\n");
				}
				else
					printf("\nStack not created\n");
				break;
			case 8: if(stack != NULL)
					displayStack(stack);
				else
					printf("\nStack not created\n");
				break;
			case 9: if(stack != NULL)
				{
					stack = destroyStack(stack);
					printf("\nStack destoryed\n");
				}
				else
					printf("\nStack not created\n");
				break;
			case 10:if(stack != NULL)
					destroyStack(stack);
				printf("\nEXIT\n");
				exit(0);

			default: printf("\nInvalid input, please try again\n");
				continue;
		}
	}
}
