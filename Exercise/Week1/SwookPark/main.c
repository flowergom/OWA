#include <stdio.h>
#include <stdlib.h>

///////문제 1  연결리스트를 이용하여 스택 자료구조를 구현해보자. ///////

typedef struct _linkedListNode
{
	int key;
	struct _linkedListNode *next;
} LLNode;

typedef struct _linkedListStack
{
	LLNode *top;
    int size;
} LLStack;


LLStack *createStack()
{
	LLStack *lls = malloc(sizeof(LLStack));
    lls->top = NULL;
    lls->size = 0;
    return lls;
}

void deleteStack(LLStack *targetStack)
{
	LLNode *nodePtr = targetStack->top;
    while (nodePtr != NULL)
    {
    	LLNode *next = nodePtr->next;
        free(nodePtr);
        nodePtr = next;
    }
    free(targetStack);
}


int push(LLStack *targetStack, int value)
{
    if (targetStack == NULL) return 0;

    LLNode *newNode = malloc(sizeof(LLNode));

    if (newNode == NULL) return 0;

    newNode->key = value;
    newNode->next = targetStack->top;
    targetStack->top = newNode;
    targetStack->size += 1;

    return 1;
}

int pop(LLStack *targetStack, int *value)
{
    if (targetStack == NULL || targetStack->top == NULL) return 0;

    *value = targetStack->top->key;
    LLNode *nodeDelete = targetStack->top;
    targetStack->top = targetStack->top->next;
    targetStack->size -= 1;
    free(nodeDelete);

    return 1;
}
///////문제 1  연결리스트를 이용하여 스택 자료구조를 구현해보자. ///////

int main(void)
{
///// 문제 1 테스트 /////

	LLStack *testStack1;
	testStack1 = createStack();

	int intTemp, i;

	push(testStack1, 10);
	push(testStack1, 10);

	for(i = 0; i < 10; i++)
	{
		if(pop(testStack1, &intTemp))
		{
			printf("poped %d\n", intTemp);
		}
	}
	deleteStack(testStack1);

///// 문제 1 테스트 /////


///// 문제 2 스택 두 개를 이용하여 큐를 만드는 방법은 무엇일까? 큐에 원소를 넣고 /////
/////(enqueue), 빼는(dequeue) 동작은 가능한 효율적이어야 한다. /////



	return 0;
}


