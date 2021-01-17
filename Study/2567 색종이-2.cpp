#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int map[101][101];
int visit[101][101];
int N;
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1,0, 0 };
int ret = 0;

void SetData(int curX,int curY)
{
	for (int ny = curY; ny < curY + 10; ny++)
	{
		for (int nx = curX; nx < curX + 10; nx++)
		{
			map[ny][nx] = 1;
		}
	}
}

void  perimete(int curY,int curX) //사각형 둘레 구하는 함수
{
	for (int i = 0; i < 4; i++)
	{
		int ny = curY + dy[i];
		int nx = curX + dx[i];

		if (ny < 0 || ny >= 101 || nx < 0 || nx >= 101 || map[ny][nx] == 0)
		{
			continue;
		}

		if (map[ny][nx] == 1 )
		{
			
		//	printf("%d %d\n", ny, nx);
			ret++;
		}
	}
}
int main()
{
	scanf("%d", &N);

	while (N--)
	{
		int x, y;

		scanf("%d %d", &y, &x);

		SetData(x, y);

	}
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			if (map[i][j] == 0)
			{
				perimete(i, j);
			}
		}
	}
	printf("%d\n", ret);

	return 0;
}