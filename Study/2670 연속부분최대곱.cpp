/*
�迭�� ���� �ε����� �ϳ��� ������ ������ ���(ũ�Ⱑ 1�� �κм����� ���� �ٷ� �ڽ��̴�.)
���ݱ��� ���ؿ� �信 ���� �迭�� now �ε��� ���� ���ؼ� ������ ���
���ݱ��� ���� ���� ������ ���� �ε��� ���� ������ �ٽ� �����ϴ� ���
���� ���� ���ݱ��� ���� ���� �����ؼ� ����ؼ� ���� ã�Ƴ����� ���
*/
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
double arr[10000];
int N;
double ret = -1;

double max(double n1, double n2)
{
	if (n1 > n2)
		return n1;

	return n2;
}

void Sequence()
{
	double temp;

	for (int i = 0; i < N; i++)
	{
		temp = 1;
		for (int j = i; j < N; j++)
		{
			temp *= arr[j];

			if (ret < temp)
			{
				ret = temp;
			}
		}
	}

}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%lf", &arr[i]);
	}
	Sequence();

	printf("%.3lf", ret);
}