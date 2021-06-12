/*
	바이러스를 어떻게 놓을지
	- 바이러스의 갯수만큼 맵에 위치시켜야함
	- 맵 전체 탐색하여 바이러스의 갯수만큼 빈 칸에 두어야함
	- dfs로 두고 다 두었으면 BFS 탐색
	
	바이러스를 놓은 뒤 탐색하여 최소시간 구하는 법
	- BFS 탐색으로 상하좌우 상태를 업데이트
	- 현재 Queue에 있는 시간+1을 하여 업데이트
	- 벽에 의해 탐색을 전부 할 수 없다면 스킵
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>

#define EMPTY 0
#define WALL 1
#define VIRUS_PLACE 2 //바이러스를 놓을 수 있는 칸
#define VIRUS 3
#define MAXIMUM 123456789
using namespace std;

queue<pair<int, int>> Que;

int N, M;//연구소의 크기, 놓을 수 있는 바이러스의 개수
int map[51][51];

int tc = 1;
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
int minTimer = MAXIMUM;

void DebugPrint(int(*PasteMap)[51])
{
	printf("TC %d\n===========================================\n",tc);
	tc++;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%3d", PasteMap[i][j]);
		}
		printf("\n");
	}
}

void copyMap(int(*PasteMap)[51], int(*OriginMap)[51])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (OriginMap[i][j] == WALL)
			{
				PasteMap[i][j] = -1;
				
			}
			else if (OriginMap[i][j] == VIRUS_PLACE)//virus를 이미 놓은 곳을 제외한 virus 놓을 수 있는 위치
			{
				PasteMap[i][j] = 0;
				
			}
			else if (OriginMap[i][j] == VIRUS)
			{
				PasteMap[i][j] = 1;
			}
		}
	}
}
int bfs()
{
	int temp_map[51][51];
	int visit[51][51];
	int maxTime = 0;

	memset(temp_map, 0, sizeof(temp_map));
	memset(visit, 0, sizeof(visit));

	copyMap(temp_map, map);
	//DebugPrint(temp_map);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (temp_map[i][j] == 1)
			{
				//printf("(%d %d)\n", i, j);
				visit[i][j] = 1;
				Que.push(make_pair(i, j));
			}
		}
		
	}

#if 1
	while (!Que.empty())
	{
		int curY = Que.front().first;
		int curX = Que.front().second;
		
		Que.pop();
		
		
		for (int i = 0; i < 4; i++)
		{
			int ny = curY + dy[i];
			int nx = curX + dx[i];

			if (ny >= N || ny < 0 || nx >= N || nx < 0 )
				continue;
			if (temp_map[ny][nx] == -1 ||visit[ny][nx] == 1)
				continue;
			if (temp_map[ny][nx] == 0 && visit[ny][nx] == 0 )
			{
				//printf("접근\n");
				visit[ny][nx] = 1;
				temp_map[ny][nx] = temp_map[curY][curX]+1;
				Que.push(make_pair(ny, nx));
			}
		}
	}//while
#endif
	//맵에서 아직 탐색하지 못한 곳이 있으면 최댓값 return
	//현재 바이러스를 셋팅 후 퍼트린 맵의 최댓 시간을 구함
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (temp_map[i][j] == 0)
				return MAXIMUM;
			if (maxTime < temp_map[i][j])
			{
				maxTime = temp_map[i][j];
			}
		}
	}

	//DebugPrint(temp_map);
	return maxTime;
}


void dfs(int virusCnt)
{
	if (virusCnt == M)
	{
		int maxTimer = 0;
		
		maxTimer = bfs();

		//현재 바이러스를 놓은 맵의 최대 시간이
		//가장 작은 시간인 경우를 계산
		minTimer = min(minTimer, maxTimer);

		return;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 2)
			{
				map[i][j] = 3;
				dfs(virusCnt + 1);
				map[i][j] = 2;
			}
		}
	}


}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	dfs(0);

	if (minTimer == 123456789)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", minTimer - 1);
	}

	return 0;
}
