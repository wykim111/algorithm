/*
	H인 경우
	위아래 대칭
	(0,0) <-> (1,0)
	(0,1) <-> (1,1)

	V인 경우
	위아래 대칭
	(0,0) <-> (0,1)
	(1,0) <-> (1,1)

*/
#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

char str[1000001];
int map[2][2] = { {1,2},{3,4}};

void convertH()
{

	for (int i = 0; i < 2; i++)
	{
		int temp = map[0][i];
		map[0][i] = map[1][i];
		map[1][i] = temp;

	//	printf("%d %d\n", map[i][0], map[i][1]);
	}
}

void convertV()
{

	for (int i = 0; i < 2; i++)
	{
		int temp = map[i][0];
		map[i][0] = map[i][1];
		map[i][1] = temp;
	}
}

void Print()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int len = 0;

	scanf("%s", str);

	len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		if (str[i] == 'H')
		{
			convertH();
		}
		else if (str[i] == 'V')
		{
			convertV();
		}
		else
		{

		}
	}
	
	Print();

	return 0;
}