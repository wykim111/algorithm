#include<stdio.h>
#include<string.h>

char map[4][4];
int tcNum = 1;

void init()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			map[i][j] = '\0';
		}	
	}
}

/*
	해당 pos에 o 또는 x로 마킹 후 3개가 연속으로 이어져 있는지 체크
*/

int checkDir(int y,int x,char usr)
{
	int cnt = 0;
	int nextY = y, nextX = x;


	//checkLeft
	while (nextX >= 0 && (map[nextY][nextX] == usr))
	{
		cnt++;
		nextX--;
	}

	if (cnt == 3)
	{
		return 1;
	}
	nextY = y;
	nextX = x;
	cnt = 0;

	//check up
	while (nextY >= 0 && (map[nextY][nextX] == usr))
	{
		cnt++;
		nextY--;
	}

	if (cnt == 3)
	{
		return 1;
	}
	nextY = y;
	nextX = x;
	cnt = 0;

	//check down
	while (nextY < 3 && (map[nextY][nextX] == usr))
	{
		cnt++;
		nextY++;
	}

	if (cnt == 3)
	{
		return 1;
	}
	nextY = y;
	nextX = x;
	cnt = 0;

	//checkRight
	while (nextX < 3 && (map[nextY][nextX] == usr))
	{
		cnt++;
		nextX++;
	}

	if (cnt == 3)
	{
		return 1;
	}
	nextY = y;
	nextX = x;
	cnt = 0;

	//check LeftUP
	while (nextX >= 0  && nextY >= 0 && (map[nextY][nextX] == usr))
	{
		cnt++;
		nextX--;
		nextY--;
	}

	if (cnt == 3)
	{
		return 1;
	}
	nextY = y;
	nextX = x;
	cnt = 0;

	//check LeftDown
	while (nextX >= 0 && nextY < 3 && (map[nextY][nextX] == usr))
	{
		cnt++;
		nextX--;
		nextY++;
	}

	if (cnt == 3)
	{
		return 1;
	}
	nextY = y;
	nextX = x;
	cnt = 0;

	//check RightUp
	while (nextX < 3 && nextY >= 0 && (map[nextY][nextX] == usr))
	{
		cnt++;
		nextX++;
		nextY--;
	}

	if (cnt == 3)
	{
		return 1;
	}
	nextY = y;
	nextX = x;
	cnt = 0;

	//check RightDown
	while (nextX < 3 && nextY < 3 && (map[nextY][nextX] == usr))
	{
		cnt++;
		nextX++;
		nextY++;
	}

	if (cnt == 3)
	{
		return 1;
	}
	nextY = y;
	nextX = x;
	cnt = 0;


	return 0;
}

int setTic(char user)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (map[i][j] == '-')
			{
				map[i][j] = user;

				for (int y = 0; y < 3; y++)
				{
					for (int x = 0; x < 3; x++)
					{
						if (checkDir(y, x, user) == 1)
							return 1;
					}
				}
				
				map[i][j] = '-';
			}
		}
	}

	return 0;
}

void Print()
{
	printf("Case %d:\n",tcNum++);
	for (int i = 0; i < 3; i++)
	{
		printf("%s\n", map[i]);
	}
}



int main()
{
	int tc;

	scanf("%d", &tc);
	getchar();
	while (tc--)
	{
		char ch;
		
		init();
		
		for (int i = 0; i < 3; i++)
		{
			scanf("%s", map[i]);
		}
		getchar();
		scanf("%c", &ch);
		getchar();

		if (setTic(ch) == 1)
		{
			Print();

		}
	
		
	}


	return 0;
}
