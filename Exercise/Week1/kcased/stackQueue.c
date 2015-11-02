#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 10

int instack[STACKSIZE];
int outstack[STACKSIZE];
int instacktop;
int outstacktop;

bool instack_isFull()
{
	if(instacktop < STACKSIZE)
		return true;
	else
		return false;
}

bool instack_isEmpty()
{
	if(instacktop < 0)
		return true;
	else
		return false;
}

bool outstack_isEmpty()
{
	if(outstacktop < 0)
		return true;
	else
		return false;
}

bool outstack_isFull()
{
	if(outstacktop < STACKSIZE)
		return true;
	else
		return false;
}

void instack_push(int num)
{
	if(instack_isFull())
	{
		instack[++instacktop] = num;
		printf("insert : %d\n", instack[instacktop]);
	}
}

void outstack_push(int num)
{
	if(outstack_isFull())
		outstack[++outstacktop] = num;
}

void instack_pop()
{
	if(outstack_isEmpty())
	{
		while(!instack_isEmpty())
		{
			outstack_push(instack[instacktop]);
			instack[instacktop--] = 0;
		}
	}
}

void outstack_pop()
{
	instack_pop();
	while(!outstack_isEmpty())
	{
		printf("delete : %d\n", outstack[outstacktop]);
		outstack[outstacktop--] = 0;
	}
}

void queue_insert(int num)
{
	instack_push(num);
}

void queue_delete()
{
	outstack_pop();
}

int main()
{
	instacktop = -1;
	outstacktop = -1;

	for(int i = 0; i<STACKSIZE; i++)
	{
		queue_insert(i);
	}

	printf("\n");

	queue_delete();

	return 0;
}
