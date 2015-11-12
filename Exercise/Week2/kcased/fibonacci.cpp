#include <stdio.h>

int count;
int numbering;

unsigned long fibo(unsigned long prevSum, unsigned long sum)
{
	unsigned long temp = sum;
	sum = prevSum + sum;
	if(count == ++numbering)
		return sum;
	else
	{
		fibo(temp, sum);
	}
}

unsigned long fibo_recur(unsigned long num)
{
	if(num == 1 || num == 2)
		return 1;
	else
		return fibo_recur(num-1) + fibo_recur(num-2);
}

int main()
{
	unsigned long fibo_sum = 0;
	scanf("%d", &count);
	numbering = 1;
	printf("Total Sum : %d\n", fibo(0,1));
	printf("Total Sum : %d\n", fibo_recur(count));
	return 0;
}
