#include<stdio.h>

int numOfPaths(int row, int col)
{

	if (row == 0 && col == 0)
	{
		return 0;
	}
	if (row == 0 || col == 0)
	{
		return 1;
	}

	return numOfPaths(row - 1, col) + numOfPaths(row, col - 1);
}

int main()
{
	int M, N;
	printf("방의 구조를 입력하세요 : ");
	scanf("%d %d", &M, &N);
	// 인덱스가 0부터이므로 M - 1, N - 1을 매개변수로 호출합니다.
	printf("총 경로의 수는 %d개입니다.\n", numOfPaths(M - 1, N - 1));
	return 0;
}