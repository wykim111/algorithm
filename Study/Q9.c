#include<stdio.h>
#include<string.h>

void ary_rcopy(int*a,const int * b,int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = b[n - i - 1];
	}
}


int main()
{
	int a[6] = { 0, };
	int b[6] = { 5,10,73,2,-5,42 };

	memset(a, 0, sizeof(a));


	ary_rcopy(a, b, sizeof(a)/sizeof(int));

	for (int i = 0; i < 6; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}