/*
1. 가장 처음에 봄버맨은 일부 칸에 폭탄을 설치해 놓는다. 모든 폭탄이 설치된 시간은 같다.
2. 다음 1초 동안 봄버맨은 아무것도 하지 않는다.
3. 다음 1초 동안 폭탄이 설치되어 있지 않은 모든 칸에 폭탄을 설치한다. 즉, 모든 칸은 폭탄을 가지고 있게 된다. 폭탄은 모두 동시에 설치했다고 가정한다.
4. 1초가 지난 후에 3초 전에 설치된 폭탄이 모두 폭발한다.
5. 3과 4를 반복한다.

6. 폭탄이 있던 칸이 (i, j)인 경우에 (i+1, j), (i-1, j), (i, j+1), (i, j-1)도 함께 파괴된다. 만약, 폭탄이 폭발했을 때, 
   인접한 칸에 폭탄이 있는 경우에는 인접한 폭탄은 폭발 없이 파괴된다. 따라서, 연쇄 반응은 없다.

- 폭탄 설치 시 시간을 저장하는 2차원 배열 선언
- 폭탄이 설치되어 있지 않은 모든 칸에 폭탄 설치
- 3초 전에 설치된 폭탄 폭발
*/

#include<stdio.h>
#include<string.h>

int bombTime[202][202];
char map[202][202];
char tempMap[202][202];
int R, C, N;

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

void init()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			tempMap[i][j] = 0;

		}
	}
}

//폭탄이 미설치 된 곳에 폭탄  설치
void setBomb()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == '.')
			{
				map[i][j] = 'O';
				bombTime[i][j] = 1;
			}
			else if(map[i][j] == 'O')
			{//기존에 설치된 위치는 시간+1
				bombTime[i][j] = (bombTime[i][j]+1);
			}
		}
	}
}

void startBomb()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (bombTime[i][j] >= 3)
			{
				map[i][j] = '.';
				bombTime[i][j] = 0;
				//4방향중 폭탄이 설치되어 있는지 확인
				//존재하면 그 폭탄을 터뜨림
				for (int dir = 0; dir < 4; dir++)
				{
					int nextY = i + dy[dir];
					int nextX = j + dx[dir];

					if (nextY >= R || nextY < 0 || nextX < 0 || nextX >= C)
						continue;
					//tempMap으로 모든 폭탄이 설치하기 전 맵 정보를 갖고 있음
					// '0'표시를 폭발하면 기존에 설치된 폭탄도 폭파시킬 위험 존재
					//기존에 설치된 폭탄은  주변  기존에 설치된 폭탄에 의해 폭발하면 안됨
					if (map[nextY][nextX] == 'O' && tempMap[nextY][nextX] == '.')
					{
						map[nextY][nextX] = '.';
						bombTime[nextY][nextX] = 0;
					}
				}//dir
			}//if bombTime
		}//j
	}//i
}
/*
void numPrint()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			printf("%d", bombTime[i][j]);
		}
		printf("\n");
	}
}
*/
void Print()
{
	for (int i = 0; i < R; i++)
	{
		printf("%s\n", map[i]);
	}
}

void copy()
{
	for (int i = 0; i <= R; i++)
	{
		for (int j = 0; j <= C; j++)
		{
			tempMap[i][j] = map[i][j];
		}
	}
}

int main()
{
	int time = 1;

	scanf("%d %d %d", &R, &C, &N);

	for (int i = 0; i < R; i++)
	{
		scanf("%s", map[i]);

		//폭탄 설치된 위치의 시간 저장
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == 'O')
			{
				bombTime[i][j] = 1;
			}
		}
	}
	if(N > 1)
	{ 
		while (1)
		{
			time++;
			init();
			//	printf("%d초후\n", time-1);
				//모든 맵에 폭탄을 설치하기전의 맵을 저장
			copy();
			setBomb();//모든 맵 폭탄 설치 및 카운트
		//	Print();

			if (time >= N)
			{
				break;
			}

			time++;
			//	printf("%d초후\n", time-1);
			setBomb();//모든 맵 폭탄 설치 및 카운트
			startBomb();
			//	Print();

			if (time >= N)
			{
				break;
			}
		}
		
	}//if N > 1

	Print();

	return 0;
}
