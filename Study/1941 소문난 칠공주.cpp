#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

char map[6][6];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
int visit[6][6];
int subVisit[6][6];
int ret = 0;

void adjacent(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
		{
			continue;
		}

		if (visit[ny][nx] == 1 && subVisit[ny][nx] == 0)
		{
			subVisit[ny][nx] = 1;
			adjacent(ny, nx);
		}
	}
}



void dfs(int dep, int y,int x,int S,int Y)
{
	if (Y >= 4)
	{
		return;
	}
	if (dep == 7 && S>=4)
	{
		int cnt = 0;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (visit[i][j] == 1 && subVisit[i][j] == 0)
				{
					subVisit[i][j] = 1;
					adjacent(i, j);
					cnt++;
					//printf("%d\n",cnt);
				}
			}
		}
		memset(subVisit, 0, sizeof(subVisit));

		if (cnt == 1)
		{
			ret++;
		}
		return;
	}
	
	for (int i = y; i < 5; i++)
	{
		for (int j = x; j < 5; j++)
		{
			if (visit[i][j] == 0)
			{
				visit[i][j] = 1;

				if (map[i][j] == 'S')
				{
					dfs(dep + 1, i, j, S + 1, Y);
				}
				if (map[i][j] == 'Y')
				{
					dfs(dep + 1, i, j, S, Y+1);
				}
				visit[i][j] = 0;
			}
		}
		x = 0;
	}

}



int main()
{


	for (int i = 0; i < 5; i++)
	{
		scanf("%s", map[i]);

		while (getchar() != '\n');
	}

	dfs(0, 0,0,0,0);
	printf("%d\n", ret);

	return 0;
}