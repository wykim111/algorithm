/*
	���� Ȱ��
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int N;
int sourness[11]; //�Ÿ�
int bitter[11];//����
long long int ret = 1e9;

//idx�� r�� ���� ����,s�� b�� �����ϰų� ���� �� �� ��� ����Ǵ� ��
void go(int idx, int r, long long int s, long long int b)
{
	if (idx == r)
	{
		int temp = abs(s - b);

		if (temp < ret)
		{
			ret = temp;
		}
		return;
	}
	/*
	//����  ��Ḧ �����ϴ� ���
	go(idx + 1, s*sourness[idx], b + bitter[idx]);
	//���� ��Ḧ ���� ���� ���� ���
	go(idx + 1, s, b);
	*/
	for (int i = idx + 1; i < N; i++)
	{
		go(i, r, s * sourness[i], b + bitter[i]);
	}
	return;
}
int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &sourness[i], &bitter[i]);
	}
	for (int i = 0; i < N; i++)//r�� �����ϴ� ���
	{
		for (int j = 0; j < N; j++)//������ �� ���� ����
		{
			go(j, i, sourness[j], bitter[j]);
		}
	}

	printf("%lld\n", ret);
	return 0;
}