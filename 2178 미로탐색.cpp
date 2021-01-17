/*
	1인지역을 BFS로 탐색하는데 visit 방문배열로 각각의 거리를 갱신하도록 함
*/
#include<iostream>
#include<queue>
#include<cstdio>

using namespace std;
int N, M;
int map[100][100];
int visit[100][100];
queue<pair<int, int>> Que;
//동서남북
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

			//맵의 범위 벗어나는 경우
			if (nextY < 0 || nextY >= M || nextX < 0 || nextX >= N)
				continue;
			//맵은 1로 통과할 수 있는 통로이면서 방문하지 않은 위치(visit[][]은 0으로 초기화 되어 있다)
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