#include<iostream>
#include<queue>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int map[1000][1000];
int copy_map[1000][1000];
int N,M;
int visit[1000][1000];
int dist[1000][1000];
//��������
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

void bfs(int y, int x)
{
	int cnt = 0;
	queue<pair<int, int>> Que;

	Que.push(make_pair(y, x));

	while (!Que.empty())
	{
		int curY = Que.front().first;
		int curX = Que.front().second;

		Que.pop();
		visit[curY][curX] = 1;
		
		//�� �κ� �߿�
		//map[y][x] == 1�� ��� �Ÿ��� 1�� �����Ͽ� Ž��
		//map[y]x] == 0�� ��� �Ÿ��� 0���� ����Ʈ �Ǿ� ����
		if(map[curY][curX] == 1)
			dist[curY][curX] = 1;


		for (int i = 0; i < 4; i++)
		{
			int ny = curY + dy[i];
			int nx = curX + dx[i];

			//���� �ʰ���
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			{
				continue;
			}
			//�湮 �� �����鼭 ���� ���� ��
			if (map[ny][nx] == 0 && visit[ny][nx] == 0)
			{
				//�� �κ� �߿�
				//���� map[y][x] == 1�� ��츦 Ž���ϹǷ�
				//�� �������� �������� �ֺ��� 0�� ������ ����
				dist[y][x]++;
				
				visit[ny][nx] = 1;
				
				Que.push(make_pair(ny, nx));
			}
		}
	}



}


int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			memset(visit, 0, sizeof(visit));
			if (map[i][j] == 1)
			{
				bfs(i, j);
			}
		}
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d", dist[i][j]);
		}
		printf("\n");
	}
	return 0;
}