#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define PLAYER1 1 // O
#define PLAYER2 2 // X

using namespace std;
int map[4][4] = { 0, };
int res = 0;
int visit[4][4] = { 0, };
int dy[] = { 0,0,1,-1,-1,-1,1,1 };
int dx[] = { 1,-1,0,0,1,-1,1,-1 };
int flag = 0;

//우
bool check_right(int y, int x, int user,int cnt)
{
	while (x < 4 && map[y][x] == user)
	{
		x++;
		cnt++;
	}

	if (cnt == 3)
	{
		return 1;
	}

	return 0;
}
//아래
bool check_down(int y, int x, int user, int cnt)
{
	while (y < 4 && map[y][x] == user)
	{
		y++;
		cnt++;
	}

	if (cnt == 3)
	{
		return 1;
	}
	return 0;
}
//우상
bool check_rightup(int y, int x, int user, int cnt)
{
	while ((x < 4 && y > 0) && map[y][x] == user)
	{
		y--;
		x++;
		cnt++;
	}

	if (cnt == 3)
	{
		return 1;
	}
	return 0;
}
//우하
bool check_rightdown(int y, int x, int user, int cnt)
{
	while ( (x < 4 && y <4) && map[y][x] == user)
	{
		y++;
		x++;
		cnt++;
	}

	if (cnt == 3)
	{
		return 1;
	}
	return 0;
}
void Check_Line(int y, int x, int user)
{
	//우, 아래, 우상 우하 탐색
	for (int i = 1; i < 4; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			//유저의 표식과 같은 경우, 우측부터 탐색
			if (check_right(i, j, user, 0))
			{
				res = user;
				return;
			}
			if (check_down(i, j, user, 0))
			{
				res = user;
				return;
			}
			if (check_rightup(i, j, user, 0))
			{
				res = user;
				return;

			}
			if (check_rightdown(i, j, user, 0))
			{
				res = user;
				return;
			}
		}
	}
}


int main()
{
	int User;

	scanf("%d", &User);

	for (int i = 0; i < 9; i++)
	{
		int y, x;

		scanf("%d %d", &y, &x);

		if (User == PLAYER1)
		{
			map[y][x] = PLAYER1;
			Check_Line(y, x,PLAYER1);
			User = PLAYER2;
		}
		else
		{
			map[y][x] = PLAYER2;
			Check_Line(y, x, PLAYER2);
			User = PLAYER1;
		}

		if (res != 0)
		{
			break;
		}
	}
	printf("%d\n", res);

	return 0;

}
