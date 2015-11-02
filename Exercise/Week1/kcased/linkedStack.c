#include <stdio.h>
#include <stdlib.h>

typedef struct _node *linknode;
struct _node
{
	int data;
	linknode nextnode;
};

linknode head;

void initNode()
{
	head = (linknode)malloc(sizeof(linknode));
	head->nextnode = NULL;
}

void push(int inputdata)
{
	linknode newnode;
	newnode = (linknode)malloc(sizeof(linknode));
	newnode->data = inputdata;
	newnode->nextnode = head->nextnode;
	head->nextnode = newnode;
	printf("PUSH : %d \n", newnode->data);
}

void pop()
{
	linknode tempnode;
	tempnode = (linknode)malloc(sizeof(linknode));
	tempnode = head->nextnode;
	head->nextnode = tempnode->nextnode;
	printf("POP : %d \n", tempnode->data);
}

int main()
{
	initNode();
	for(int i = 1; i < 15 ; i = i+2)
	{
		push(i);
	}

	linknode temp;
	temp = (linknode)malloc(sizeof(linknode));
	for(temp = head->nextnode; temp; temp = temp->nextnode)
	{
		pop();
	}
}
