#include <stdio.h>

#define MAX 1024
int stack[MAX];
int top = -1;

void push(int data) {
  stack[++top] = data;
}

int pop() {
  return stack[top--];
}

int main() {

  int a[] ={1,3,5,7,8,2,6,4};
  int i;

  printf("push : ");
  for(i = 0; i < 8;i++)
  {
  	push(a[i]);
  	printf("%d ",a[i]); 
  }

  printf("\n");
  printf("pop  : ");
  for(i = 0; i < 8;i++)
  	printf("%d ",pop());
  return 0;
}