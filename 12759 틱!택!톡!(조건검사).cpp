#include<cstdio>
#include<iostream>

#define PLAYER1 1
#define PLAYER2 2
using namespace std;

int map[4][4];
int res = 0;
bool Check_Line(int user)
{
	//직선(우측, 아래)
	for (int i = 1; i < 4; i++)
	{
		if (map[i][1] == user)
		{
			if (map[i][1] == map[i][2] && map[i][2] == map[i][3])
			{
				res = user;
				return 1;
			}
			else if(map[1][i] == map[2][i] && map[i][2] == map[3][i])
			{
				res = user;
				return 1;
			}
			else if (map[1][1] == map[2][2] && map[2][2] == map[3][3])//대각선
			{
				res = user;
				return 1;
			}
			else if (map[3][1] == map[2][2] && map[2][2] == map[1][3])//대각선
			{
				res = user;
				return 1;
			}
		}
		
	}
	return 0;
}


int main()
{
	int User;

	for (int i = 0; i < 9; i++)
	{
		int y, x;

		if (User == PLAYER1)
		{
			map[y][x] = PLAYER1;
		}
		else
		{
			map[y][x] = PLAYER2;
		}
	}
}