/*
	��� ���ϱ�
	����� �����ϴ� ������ �迭�� ����
	K��°�� ���� ���� ���
*/
#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

int N, K;
vector<int>divisor;

void factor()
{
	for (int i = 1; i <= N; i++)
	{
		if (N%i == 0)
		{
			divisor.push_back(i);
		}
	}
}

int main()
{
	scanf("%d %d", &N, &K);
	factor();

	printf("%d\n", divisor[K - 1]);

	return 0;
}