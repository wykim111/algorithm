/*
	1�������� BFS�� Ž���ϴµ� visit �湮�迭�� ������ �Ÿ��� �����ϵ��� ��
*/
#include<iostream>
#include<queue>
#include<cstdio>

using namespace std;
int N, M;
int map[100][100];
int visit[100][100];
queue<pair<int, int>> Que;
//��������
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
//int min_ret = 9999999;

void bfs(int y, int x)
{
	Que.push(make_pair(y, x));
	visit[y][x] = 1;

	while (!Que.empty())
	{
		int curY = Que.front().first;
		int curX = Que.front().second;
		Que.pop();
		

		for (int i = 0; i < 4; i++)
		{
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			//���� ���� ����� ���
			if (nextY < 0 || nextY >= M || nextX < 0 || nextX >= N)
				continue;
			//���� 1�� ����� �� �ִ� ����̸鼭 �湮���� ���� ��ġ(visit[][]�� 0���� �ʱ�ȭ �Ǿ� �ִ�)
			if (map[nextY][nextX] == 1 && visit[nextY][nextX] == 0)
			{
				visit[nextY][nextX] = visit[curY][curX] + 1;
				Que.push(make_pair(nextY, nextX));
			}
		}
	}
}

int main()
{
	scanf("%d %d", &M, &N);

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	bfs(0, 0);
	printf("%d\n", visit[M-1][N-1]);

	return 0;
}