/*
	����Ž������ B �̻��� ���� ã�´� �׸��� �̻��� ���� �ִ� �ε��� ���� ���� �ε����� ���� ã�� Ű������ ���̸� ��
	Ű ������ ���̰� ���� ���� ���� �������� �̵���Ų��.
*/

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int A, B;
int arr[5];
int N;


int main()
{
	int gap =1000;
	int ret = 0;

	scanf("%d %d", &A, &B);
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	
	for (int i = 0; i < N; i++)
	{
		if (abs(B - arr[i]) < gap)
		{
			gap = abs(B - arr[i]);
		}
	}

	if (abs(B - A) > gap + 1)
		ret = gap + 1;
	else
		ret = abs(B - A);

	printf("%d\n", ret);

	return 0;
}