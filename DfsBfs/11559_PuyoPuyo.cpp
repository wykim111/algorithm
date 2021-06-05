/*
같은 색 뿌요가 4개 이상 상하좌우로 연결되어 있으면 연결된 같은 색 뿌요들이 한꺼번에 없어진다. 이때 1연쇄가 시작된다.

뿌요들이 없어지고 나서 위에 다른 뿌요들이 있다면, 역시 중력의 영향을 받아 차례대로 아래로 떨어지게 된다.

아래로 떨어지고 나서 다시 같은 색의 뿌요들이 4개 이상 모이게 되면 또 터지게 되는데, 터진 후 뿌요들이 내려오고 다시 터짐을 반복할 때마다 1연쇄씩 늘어난다.

===============================================================================================================================================================

총 12개의 줄에 필드의 정보가 주어지며, 각 줄에는 6개의 문자가 있다.

이때 .은 빈공간이고 .이 아닌것은 각각의 색깔의 뿌요를 나타낸다.

R은 빨강, G는 초록, B는 파랑, P는 보라, Y는 노랑이다.

- 맨 밑 행부터 위로 탐색 시작
- dfs로 같은 글자를 4방향(동,서,남,북) 찾아서 '.'로 대체하고 위에 글자가 있으면 밑으로 내린다.


*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

char map[12][7];
int visit[12][7];

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
int cnt = 0;
void DebugPrint()
{
	for (int i = 0; i < 12; i++)
	{
		printf("%s\n", map[i]);
	}
	
}

void down_puyo()
{
	//맵의 행 범위(nextY-1이 0보다 작은경우 예외처리)를 체크하고이미 방문한 지점에는 위에 컬러가 있으면 밑으로 내림
	/*
		열을 기준으로 행을 탐색하여 현재 pos가 '.'이고 위에 데이터가 있으면 내린다.
	*/
	for (int curX = 0; curX < 6; curX++)
	{
		
			//while문이 없으면 1칸 밖에 내리지 못함
			while (1)
			{
				int flag = 0;
				
				for (int curY = 11; curY >= 1; curY--)
				{
					// 현재 pos가 '.'이며, 위의 pos가 컬러인 경우
					if (map[curY][curX] == '.' && map[curY - 1][curX] != '.')
					{
						flag = 1;
						map[curY][curX] = map[curY - 1][curX];
						map[curY - 1][curX] = '.';
					}

				}//curY
				if (flag == 0)
				{
					break;
				}
			
			}
	}
}

void dfs(int y, int x, char color)
{
	

	for (int i = 0; i < 4; i++)
	{
		int nextY = y + dy[i];
		int nextX = x + dx[i];

		if (nextY < 0 || nextY > 11 || nextX < 0 || nextX > 11)
			continue;

		if (visit[nextY][nextX] == 1)
			continue;

		if (map[nextY][nextX] == color)
		{
			visit[nextY][nextX] = 1;
			cnt++;
			dfs(nextY, nextX, color);
		}
	}

}

void remove()
{
	//이미 방문한 지점(같은 컬러)
	for (int i = 11; i >= 0; i--)
	{
		for (int j = 0; j < 6; j++)
		{
			if (visit[i][j] == 1)
			{
				map[i][j] = '.';
			}
		}

	}
}

int main()
{
	int retCnt = 0;
	for (int i = 0; i < 12; i++)
	{
		scanf("%s", map[i]);
	}

	//DebugPrint();

	while (1)
	{
		int flag = 0;

		for (int i = 11; i >= 0; i--)
		{
			for (int j = 0; j < 6; j++)
			{
				if (map[i][j] != '.')
				{
					cnt = 1;
					memset(visit, 0, sizeof(visit));

					visit[i][j] = 1;
					dfs(i, j, map[i][j]);

					if (cnt >= 4)
					{
						remove();
						flag = 1;
					}
				}// if (map[i][j] != '.')
			}//j

		}//i
		//더이상 터지는 puyo가 없는 경우
		if (flag == 0)
		{
			break;
		}
		down_puyo();
		retCnt++;
		
	}//while

	printf("%d\n", retCnt);


	return 0;
}
