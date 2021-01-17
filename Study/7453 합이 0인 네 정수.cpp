
/*
	1. 4���� �迭�� 2���� �����ϴ�. {ù ��° �迭, �� ��° �迭}, {�� ��° �迭, �� ��° �迭}

2. ù ��° �迭�� �� ��° �迭�� ������ ��� ���� �̸� ��ó�� �� �ʿ� ���� 
   �� ��° �迭�� �� ��° �迭�� ��� ������ �ո� �̸� ��ó���صΰ� ������������ �����մϴ�.
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

int N;
ll arr[4][4001];
vector<ll> vt;
ll ret = 0;

int main()
{
	scanf("%d", &N);

	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			scanf("%lld", &arr[i][j]);
		}
	}
	//3���� �迭���� �� ���Ұ� 4���� �迭 ���Ҹ��� ���� ����
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			vt.push_back((arr[2][i] + arr[3][j]));
		}
	}

	sort(vt.begin(), vt.end());
	// �ش� �����Ͱ� �����ϴ� ���� ������ ������ ���� Ž��
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ll GroupA = arr[0][i] + arr[1][j];
			ll start = lower_bound(vt.begin(), vt.end(), -GroupA) - vt.begin();
			ll end = upper_bound(vt.begin(), vt.end(), -GroupA) - vt.begin();

			if ((GroupA + vt[start]) == 0)
			{
				ret += (end - start);
			}
		}
	}
	printf("%lld\n", ret);

	return 0;
}