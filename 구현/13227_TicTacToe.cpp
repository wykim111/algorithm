/*
	1. 3 by 3 맵 입력
	2. 각 행과 열,대각선(좌하, 우하) 탐색하여 어느 한 라인이라도 3개이상 같은 모양 일치하면 "YES"
	3. '0' 혹은 'X' 차례에 진행하였는데 2번과 같이 일치하는 경우가 없으면 "NO" 

*/

#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

char map[4][4];
int first_selection_cnt = 0;
char first_selection_pla;

void input()
{
	for (int i = 0; i < 3; i++)
	{
		scanf("%s", map[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (map[i][j] == '.')
			{
				first_selection_cnt++;
			}
		}
	}





}

bool check_dir(char player)
{
	int cnt = 0;

	//행 검사
	for (int i = 0; i < 3; i++)
	{
		cnt = 0;
		for (int j = 0; j < 3; j++)
		{
			if (player == map[i][j])
			{
				cnt++;
			}
		}

		if (cnt == 3)
		{
			return true;
		}
	}
	//열 검사
	for (int j = 0; j < 3; j++)
	{
		cnt = 0;
		for (int i = 0; i < 3; i++)
		{
			if (player == map[i][j])
			{
				cnt++;
			}
		}

		if (cnt == 3)
		{
			return true;
		}
	}
	//대각선 검사
	//좌하 
	if ((player == map[0][0]) && (map[0][0] == map[1][1]) && (map[1][1] == map[2][2]))
	{
		return true;
	}
	//우하
	if ((player == map[0][2]) && (map[0][2] == map[1][1]) && (map[1][1] == map[2][0]))
	{
		return true;
	}

	return false;
}

void solution()
{
	bool answer = false;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (check_dir('X') == true)
			{
				answer = true;
				break;

			}
			else if (check_dir('O') == true)
			{
				answer = true;
				break;

			}
		}

		if (answer == true)
		{
			break;
		}

	}

	if (answer == true)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}


}

int main()
{
	input();
	solution();

	return 0;
}
