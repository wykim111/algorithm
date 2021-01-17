#include <stdio.h>
#include <string.h>

#define BIG 2 //큰 공
#define SMALL 1// 작은 공


void A(int* a)
{
	int idx1 = 0;
	int idx2 = 1;
	int temp;

	temp = a[idx1];
	a[idx1] = a[idx2];
	a[idx2] = temp;

}
void B(int* a)
{
	int idx1 = 0;
	int idx2 = 2;
	int temp;

	temp = a[idx1];
	a[idx1] = a[idx2];
	a[idx2] = temp;

}
void C(int* a)
{
	int idx1 = 0;
	int idx2 = 3;
	int temp;

	temp = a[idx1];
	a[idx1] = a[idx2];
	a[idx2] = temp;

}
void D(int* a)
{
	int idx1 = 1;
	int idx2 = 2;
	int temp;

	temp = a[idx1];
	a[idx1] = a[idx2];
	a[idx2] = temp;

}
void E(int* a)
{
	int idx1 = 1;
	int idx2 = 3;
	int temp;

	temp = a[idx1];
	a[idx1] = a[idx2];
	a[idx2] = temp;

}
void F(int* a)
{
	int idx1 = 2;
	int idx2 = 3;
	int temp;

	temp = a[idx1];
	a[idx1] = a[idx2];
	a[idx2] = temp;

}
int main()
{
	int arr[4];
	char str[200];
	int size;
	int SmallPos = 0;
	int BigPos = 0;

	arr[0] = SMALL;
	arr[3] = BIG;

	scanf("%s", str);

	size = strlen(str);

	for (int i = 0; i < size; i++)
	{
		switch (str[i])
		{
		case 'A':
			A(arr);
			break;
		case 'B':
			B(arr);
			break;
		case 'C':
			C(arr);
			break;
		case 'D':
			D(arr);
			break;
		case 'E':
			E(arr);
			break;
		case 'F':
			F(arr);
			break;
		
		default:
			break;
		}
	}
	//작은 공, 작은 공 찾기
	for (int i = 0; i < 4; i++)
	{
		if (arr[i] == SMALL)
		{
			SmallPos = i;
		}
		else if (arr[i] == BIG)
		{
			BigPos = i;
		}
		else
		{

		}
	}
	printf("%d\n",SmallPos+1);
	printf("%d\n", BigPos + 1);

	return 0;
}