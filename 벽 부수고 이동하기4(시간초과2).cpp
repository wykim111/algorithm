#include<iostream>
#include<cstdio>
#include <queue>
#include<cstring>
#include <cstdlib>
using namespace std;

int N, M;
char smap[1001][1001];
int  map[1001][1001];
int visit1[1001][1001] = { 0, };
int visit2[1001][1001] = { 0, };
int group_Table[1001*1001] = { 0, };
int group_Check[1001*1001] = { 0, };

int temp[1001][1001] = { 0, };//0인 영역 tag를 붙여 저장

queue<pair<int, int>> Que1;
queue<pair<int, int>> Que2;
//동서남북
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int is_range(int ny, int nx)
{
	if (ny < 0 || ny >= N || nx < 0 || nx >= M)
	{
		return 0;
	}
	return 1;
}
/*
	해당 위치가 0인 경우
*/
void BFS(int y,int x)
{
	while (!Que1.empty())
	{
		int curY = Que1.front().first;
		int curX = Que1.front().second;

		Que1.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = curY + dy[i];
			int nx = curX + dx[i];

			if (is_range(ny, nx) == 0)
				continue;
			if (map[ny][nx] == 0 && !group_Check[temp[ny][nx]])
			{
				map[curY][curX] += group_Table[temp[ny][nx]];
				group_Check[temp[ny][nx]] = 1;
			}
		}
		memset(group_Check, 0, sizeof(group_Check));
	}
}


void input()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", smap[i]);

		for (int j = 0; j < strlen(smap[i]); j++)
		{
			if (smap[i][j] >= '0' && smap[i][j] <= '9')
				map[i][j] = smap[i][j] - '0';
			
			if (map[i][j] == 1)
			{
				//1인 지점 큐에 미리 저장
				Que1.push(make_pair(i,j));
			}
		}
	}
	/*
	printf("map 변환\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
	*/
}
void DFS(int y, int x, int cnt)
{
	visit1[y][x] = 1;
	temp[y][x] = cnt;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (is_range(ny, nx) == 0)
			continue;

		if (map[ny][nx] == 0 && !visit1[ny][nx])
		{
			DFS(ny, nx, cnt);
		}

	}
}
void Process()
{
	int cnt = 1;
	//DFS
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0 && visit1[i][j] == 0)
			{
				//	printf("진입\n");
				DFS(i, j,cnt);
				cnt++;
			}
		}

	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			//영역으로 묶은 각 영역들의 '0'의 개수 저장
			group_Table[temp[i][j]]++;
		}

	}

	
	//BFS
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1 && visit1[i][j] == 0)
			{
			//	printf("진입\n");
				BFS(i, j);
			}
		}
		
	}
	
}
void RES_Print()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d", map[i][j]%10);
		}
		printf("\n");
	}
}
int main()
{
	input();
	Process();
	RES_Print();

	return 0;
}