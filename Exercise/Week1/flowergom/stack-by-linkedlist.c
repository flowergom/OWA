#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int key;
	struct _node *next;
}node;

node *list = NULL;
node *top = NULL;

void init_stack() {
  list = (node *)malloc(sizeof(node));
  top = (node *)malloc(sizeof(node));

  list->key =0;
  list->next = NULL;

  top->key = 0;
  top->next = NULL;
}

void push(int data) {
	node *newNode;
  	newNode = (node *)malloc(sizeof(node));
  	newNode->key = data;
  	newNode->next = NULL;

  if (list == NULL){
  	list = newNode;
  } else {
  	node *temp = list;
  	while(temp->next != NULL) {
  		temp = temp->next;
  	}
  	temp->next = newNode;
  }
  top = newNode;
}

int pop() {
  node *topNode = top;
  int ret = 0;

  if (list == top) { // push data only one! 
    list = NULL;
    top = NULL;
  } else {
    node *currentTop = list;
    while (currentTop != NULL && currentTop->next != top)
    {
    	currentTop = currentTop->next;
    }
    top = currentTop;
    currentTop->next = NULL;
  }
  ret = topNode->key;
  free(topNode);
  return ret;
}

int main() {

  int a[] ={1,3,5,7,8,2,6,4};
  int i;

  init_stack();
  printf("push : ");
  for(i = 0; i < 8;i++)
  {
  	push(a[i]);
  	printf("%d ",a[i]); 
  }

  printf("\n");
  printf("pop  : ");
  for(i = 0; i < 8;i++)
  {
  	printf("%d ",pop()); 
  }
  return 0;
}