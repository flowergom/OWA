#include <stdio.h>
#include <stdlib.h>

///////Week1에서 사용한 스택 ///////
typedef struct _linkedListNode
{
	int key;
	struct _linkedListNode *next;
	//struct _linkedListNode *prev;
} LLNode;

typedef struct _linkedListStack
{
	LLNode *top;
	int size;
} LLStack;

static LLStack *createStack(void);
static void deleteStack(LLStack *targetStack);
static int push(LLStack *targetStack, int value);
static int pop(LLStack *targetStack, int *value);
///////Week1에서 사용한 스택 ///////

static int printHanoi(LLStack *postA, LLStack *postB, LLStack *postC); // hanoi 탑 출력
static int moveHanoi(LLStack **post, int from, int to, int other, int height); // hanoi 탑 이동.


#define postLoads 100

int main(void)
{
//// 1 하노이 탑 문제.////
	LLStack *post[3] = {NULL,};

	post[0] = createStack();//
	post[1] = createStack();// 기둥 3개 만듬. 각각의 스택을 기둥1 기둥2 기둥3 으로 생각.
	post[2] = createStack();//

	char inputTemp[10] = {0,};

	printf("Number of Disk? \n");// 하노이 탑 높이.
	fflush(stdout);
	fgets(inputTemp,10,stdin);

	int numOfDisk = 0;

	numOfDisk = atoi(inputTemp);
	printf("Number of Disk : %d.\n",numOfDisk);
	fflush(stdout);

	int i;
	for (i = 0; i < numOfDisk; i++)
	{
		push(post[0], numOfDisk - i);
	}

	printHanoi(post[0], post[1], post[2]);//recursive알고리즘 사용해서 하노이탑 수행하는 함수.

	moveHanoi(post, 0, 1, 2, numOfDisk);

	deleteStack(post[0]);
	deleteStack(post[1]);
	deleteStack(post[2]);
	return 0;
//// 1 하노이 탑 문제 끝.////

// 2 closest pair 알고리즘 제시 문제
// 2.1)
//	n 개의 점들을 하나의 x축 값을  기준으로 축의 왼쪽에 n/2개의 점이 있고 축의 오른쪽에 n/2개의 점이 오도록 한다.
// 예를 들어 x=a 를 기준으로 했을때 이 축의 좌측과 우측에 있는 점의 개수가 각각 n/2개가 된다고 가정한다.

// 2.2)
// 축의 왼쪽에 있는 n/2개의 점들끼리 비교해서 최소거리 Lmin 구하고 오른쪽에 있는 n/2개의 점들끼리 비교해서 최소거리 Rmin을 구한다.

// 2.3)
// Lmin이 Rmin보다 작을 경우, 이제 측 왼쪽에 있는 모든 점들 각각에 대해서
// 축 오른쪽에 있는 점들과의 거기를 재서  Lmin보다 짧은 거리가 있는지비교하는데,
// 예를 들어 측 왼쪽에있는 점 (x1,y1)하나에 대해서 축 오른쪽에 있는 점 중에서 넉넉잡아서 다음 조건을 만족시키는 점들에 대해서만 거리를
// 계산하면 된다. (a<x<a+Lmin) and (y1+Lmin < y < y1+Lmin)
// 축 오른쪽에 있는 점 중에서 이조건은 만족시키는 점의 개수는 최악의 경우에도 6개를 넘지 못한다.
// 왼쪽에 있는 n/2 개의 점 각각에 대해서 최대 6개의 오른쪽에 있는 점을 비교해야 하므로 최악의 경우 3n.
// 대충 복잡도는 O(n)

// 복잡도 최종 정리하면 2.2)과정을 n, n/2, n/4, n/8 ... 으로 나눈  점 개수가 2될때까지 하므로  log n

// 2.3)번과정은  n개 점일때 한번, n/2일 때 2번, n/4일 때 4번 ... 이렇게 하니까 최종 복잡도는
// (n/2 2번해도  점개수가 n일때에 절반이니까  n개 점일때 한번 하는것과 계산량은 같음.)
// O(n log n)
//
// 2 closest pair 알고리즘 제시 문제 끝 (알고리즘 설명한다고 설명했는데 코드는 없음.)

}


static int moveHanoi(LLStack **post, int from, int to, int other, int height)
{
	if(height < 1)
		return 0;

	moveHanoi(post, from, other, to ,height - 1);

	int intTemp;

	pop(post[from], &intTemp);
	push(post[to], intTemp);
	printHanoi(post[0], post[1], post[2]);

	moveHanoi(post, other, to, from ,height - 1);

	return 0;
}

#ifndef MAX
	#define MAX(a,b) (((a)>(b))?(a):(b))
#endif

static int printHanoi(LLStack *postA, LLStack *postB, LLStack *postC)
{
	if(postA == NULL || postB == NULL || postC == NULL)
	{
		return -1;
	}
	int maxNum = 0;

	maxNum = MAX(MAX(postA->size, postB->size), postC->size);

	int i;
	LLNode *tempA = NULL;
	LLNode *tempB = NULL;
	LLNode *tempC = NULL;

	for(i = maxNum;i > 0;i--)
	{
		if(tempA == NULL && postA->size == i)
		{
			tempA = postA->top;
		}
		if(tempB == NULL && postB->size == i)
		{
			tempB = postB->top;
		}
		if(tempC == NULL && postC->size == i)
		{
			tempC = postC->top;
		}

		if(tempA != NULL)
		{
			printf("%d\t", tempA->key);
			tempA = tempA->next;
		}
		else
		{
			printf(" \t");
		}

		if(tempB != NULL)
		{
			printf("%d\t", tempB->key);
			tempB = tempB->next;
		}
		else
		{
			printf(" \t");
		}

		if(tempC != NULL)
		{
			printf("%d", tempC->key);
			tempC = tempC->next;
		}
		else
		{
			printf(" ");
		}

		printf("\n");
	}
	printf("A\tB\tC\n\n");
	return 0;
}


///////Week1에서 사용한 스택  함수///////

static LLStack *createStack()
{
	LLStack *lls = malloc(sizeof(LLStack));
	lls->top = NULL;
	lls->size = 0;
	return lls;
}

static void deleteStack(LLStack *targetStack)
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


static int push(LLStack *targetStack, int value)
{
	if (targetStack == NULL) return -1;

	LLNode *newNode = malloc(sizeof(LLNode));

	if (newNode == NULL) return -1;

	newNode->key = value;
	newNode->next = targetStack->top;
	targetStack->top = newNode;
	targetStack->size += 1;

	return 0;
}

static int pop(LLStack *targetStack, int *value)
{
	if (targetStack == NULL || targetStack->top == NULL) return -1;

	*value = targetStack->top->key;
	LLNode *nodeDelete = targetStack->top;
	targetStack->top = targetStack->top->next;
	targetStack->size -= 1;

	free(nodeDelete);

	return 0;
}
///////Week1에서 사용한 스택 함수 ///////
