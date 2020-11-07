/*
1. 가장 처음에 주사위에는 모든 면에 0이 적혀져 있다.
2. 주사위를 굴렸을 때, 이동한 칸에 쓰여 있는 수가 0이면, 
   주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다.
3. 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 
   칸에 쓰여 있는 수는 0이 된다.

   주사위 구성 -> 지도 위에 윗 면이 1이고, 동쪽을 바라보는 방향이 3인 상태로 놓여져 있음

   윗면 : 1
   아랫면 : 6

   좌측면 :4
   우측면 : 3

   앞면 : 2
   뒷면 5

   동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4
*/
#include<stdio.h>

int N, M, x, y, K;
int map[21][21];
int dir[1000];

int dice[7];

void rollDice(int move)
{
	int  tempdice[7];

	for (int i = 0; i < 7; i++)
	{
		tempdice[i] = dice[i];
	}


	if (move == 1) //동
	{
		dice[1] = tempdice[4];
		dice[4] = tempdice[6];
		dice[6] = tempdice[3];
		dice[3] = tempdice[1];

	}
	else if (move == 2)//서
	{
		dice[1] = tempdice[3];
		dice[3] = tempdice[6];
		dice[6] = tempdice[4];
		dice[4] = tempdice[1];
	}
	else if (move == 3)//북
	{
		dice[1] = tempdice[2];
		dice[2] = tempdice[6];
		dice[6] = tempdice[5];
		dice[5] = tempdice[1];


	}
	else//남
	{
		dice[1] = tempdice[5];
		dice[5] = tempdice[6];
		dice[6] = tempdice[2];
		dice[2] = tempdice[1];

	}
}

int main()
{
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < K; i++)
	{
		scanf("%d", &dir[i]);
	}
	int curX = x;
	int curY = y;

	for (int i = 0; i < K; i++)
	{
		int move = dir[i];
		int ny=curY, nx=curX;

		if (move == 1)//동
		{
			ny = curY + 1;

		}
		else if (move == 2)//서
		{
			ny = curY - 1;
		}
		else if (move == 3)//북
		{
			nx = curX - 1;
		}
		else//남
		{
			nx = curX + 1;
		}

		//범위를 벗어나는 경우
		if (nx < 0 || nx >= N || ny < 0 || ny >= M)
		{
			//printf("진입\n");
			continue;
		}

		rollDice(move);
			
		if (map[nx][ny] == 0)
		{	
			map[nx][ny] = dice[6];
		}
		else
		{
			dice[6] = map[nx][ny];
			map[nx][ny] = 0;
		}

		printf("%d\n", dice[1]);

		curX = nx;
		curY = ny;
	}


	return 0;
}

