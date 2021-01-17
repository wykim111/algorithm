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
	printf("���� ������ �Է��ϼ��� : ");
	scanf("%d %d", &M, &N);
	// �ε����� 0�����̹Ƿ� M - 1, N - 1�� �Ű������� ȣ���մϴ�.
	printf("�� ����� ���� %d���Դϴ�.\n", numOfPaths(M - 1, N - 1));
	return 0;
}