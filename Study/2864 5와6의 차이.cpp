/*
	5인 경우 6으로 바꾸어 최대값을 계산
	6인 경우 5로 바꾸어 최솟값을 계산
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int retMin = 0;
int retMax = 0;

char A[8], B[8];

int convertSix(int size1,int size2)
{
	int num = 0;

	for (int i = 0; i < size1; i++)
	{
		if (A[i] == '5')
			A[i] = '6';
	}

	for (int i = 0; i < size2; i++)
	{
		if (B[i] == '5')
			B[i] = '6';
	}

	num = atoi(A) + atoi(B);
	
	return num;
}

int convertFive(int size1, int size2)
{
	int num = 0;

	for (int i = 0; i < size1; i++)
	{
		if (A[i] == '6')
			A[i] = '5';
	}

	for (int i = 0; i < size2; i++)
	{
		if (B[i] == '6')
			B[i] = '5';
	}

	num = atoi(A) + atoi(B);

	return num;
}

int main()
{
	int len1 = 0, len2 = 0;

	scanf("%s %s", A, B);

	while (getchar() != '\n');

	len1 = strlen(A);
	len2 = strlen(B);

	retMax = convertSix(len1,len2);
	retMin = convertFive(len1,len2);

	printf("%d %d\n", retMin, retMax);

	return 0;
}

