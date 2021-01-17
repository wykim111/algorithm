/*
map의 어떤 칸에 적혀 있는 숫자는, 그 칸과 인접해 있는 여덟 개의 칸 중에서 지뢰가 들어 있는 칸이 몇 개인지를 나타내 준다. 물론 인접한 칸이 map 내부에 있는 경우에 대해서만 생각하면 된다. 예제를 보면 더 잘 이해할 수 있을 것이다.

이번 문제 조금 업그레이드 된 지뢰 찾기로, 한 칸에 한 개의 지뢰가 있는 것이 아니고, 한 칸에 여러 개(1 이상 9 이하)의 지뢰가 묻혀 있는 게임이다. 따라서 map의 어떤 칸에 적혀 있는 숫자는, 그 칸과 인접해 있는 여덟 개의 칸들에 들어 있는 지뢰의 총 개수가 된다.

0. 원본 맵에 영향이 안 가는 복사 맵을 따로 만들어 데이터를 저장하도록 한다.
1. '.'를 기준으로 8개의 방향으로 숫자들이 있다면 그 숫자들을 저장한다. input으로 숫자를' 입력하면 해당좌표를 '*'로 저장 및 출력  
2. 그 숫자가 10개 이상이면 'M'을 출력한다.
*/

#include<stdio.h>

char map[1001][1001];
char copyMap[1001][1001];
int N;

//동서남북 좌상 좌하 우하 우상
int dy[] = { 0,0,1,-1,-1,1,1,-1 };
int dx[] = { 1,-1,0,0,-1,-1,1,1 };

int mine(int y, int x)
{
	int cnt = 0;

	for (int i = 0; i < 8; i++)
	{
		int nextY = y + dy[i];
		int nextX = x + dx[i];

		if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
			continue;
		if (map[nextY][nextX] >= '1' && map[nextY][nextX] <= '9')
		{
			cnt += (map[nextY][nextX] - '0');
		}
	}
	return cnt;
}
void printMine()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] >= '1' && map[i][j] <='9')
			{
				copyMap[i][j] = '*';
			}
		}
	}
}

void Print()
{

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%c", copyMap[i][j]);
		}
		printf("\n");
	}

}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", map[i]);
	}
	//input으로 입력한 Map에 숫자가 있으면 지뢰이므로 copyMap에 '*'로 저장
	printMine();

	// '.'찾아서 근처에 숫자가 있다면 연산한 뒤 현재 좌표에 숫자를 저장한다.
	// 10 이상이면 'M'출력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == '.')
			{
				if(mine(i,j) < 10) // 숫자 저장
					copyMap[i][j] = mine(i, j) + '0';
				else // 10 이상이면 'M' 저장
				{
					copyMap[i][j] = 'M';
				}
			}

		
		}
	}
	Print();

	return 0;
}