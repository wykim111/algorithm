/*
	���� 3�� �ξ�� �ϸ� �� ���� �ּڰ��� �Ǿ�� ��
	1. �ش� ���� ��ġ�� �ڸ��� �´��� �˻�(���� ��� ���)
	2. �ش� ������ ���� ���� �� �ִٸ� 5���� ��ǥ �湮 üũ
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
 
using namespace std;

int N;
int map[10][10];
int visit[10][10];
int retMin = (int)1e9;

bool check(int curY,int curX)
{
	if (curY - 1 >= 0 && curY + 1 < N && curX - 1 >= 0 && curX + 1 < N)
	{
		if(!visit[curY][curX] && !visit[curY-1][curX] && !visit[curY+1][curX] && !visit[curY][curX+1]&& !visit[curY][curX-1])
			return true;
	}

	return false;
}

void dfs(int dep,int curY, int curX,int sum)
{
	if (dep == 3)
	{
		retMin = min(sum, retMin);

		return;
	}
	//�ش� �� ��ġ Ž
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			//5���� �������� �湮�� ���� ������, ���� ������ �ʰ����� ���� �߰����� Ž��
			if (check(i, j) == true )
			{
				visit[i][j] = visit[i - 1][j] = visit[i + 1][j] = visit[i][j - 1] = visit[i][j + 1] = true;
				sum += (map[i][j] + map[i - 1][j] + map[i + 1][j] + map[i][j - 1] + map[i][j + 1]);
				dfs(dep+1,i, j,sum);
				sum -= (map[i][j] + map[i - 1][j] + map[i + 1][j] + map[i][j - 1] + map[i][j + 1]);
				visit[i][j] = visit[i - 1][j] = visit[i + 1][j] = visit[i][j - 1] = visit[i][j + 1] = false;
			}

		}
	}

}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
			
		}
	}
	dfs(0, 0, 0, 0);

	printf("%d\n", retMin);

	return 0;
}