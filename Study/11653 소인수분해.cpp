/*
	1.2���� N���� ó���� ������ �������� ���� ã�´�.
	2.������ �������ٸ� �ش� ���� 1���� ���� �ݺ��Ѵ�.
	3. ���� 1�� �Ǹ� ����
*/

#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;
int N;

vector<int> vt;

int main()
{
	int divisor, divisored;//���� ������

	scanf("%d", &N);
	
	divisored = N; 

	while (divisored != 1)
	{
		for (divisor = 2; divisor <= divisored; divisor++)
		{
			if (divisored % divisor == 0)
			{
				divisored /= divisor;
				vt.push_back(divisor);
				divisor = 1;
			}
		}
	}

	for (int i = 0; i < vt.size(); i++)
	{
		printf("%d\n", vt[i]);
	}

	return 0;
}