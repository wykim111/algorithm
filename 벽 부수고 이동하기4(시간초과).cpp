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
//동서남북
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
		
		//이 부분 중요
		//map[y][x] == 1인 경우 거리를 1로 설정하여 탐색
		//map[y]x] == 0인 경우 거리는 0으로 디폴트 되어 진행
		if(map[curY][curX] == 1)
			dist[curY][curX] = 1;


		for (int i = 0; i < 4; i++)
		{
			int ny = curY + dy[i];
			int nx = curX + dx[i];

			//범위 초과시
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			{
				continue;
			}
			//방문 안 했으면서 벽이 없는 곳
			if (map[ny][nx] == 0 && visit[ny][nx] == 0)
			{
				//이 부분 중요
				//현재 map[y][x] == 1인 경우를 탐색하므로
				//이 포지션을 기준으로 주변에 0이 있으면 증가
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