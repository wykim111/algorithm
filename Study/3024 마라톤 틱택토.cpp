#include<stdio.h>

int N;
char map[32][32];
char ret;

int dy[] = { 0, 0,1,-1,-1,1,1,-1 };
int dx[] = { 1,-1,0,0,1,1,-1,-1 };

int innerArea(int nextY, int nextX)
{
	if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
		return 0;

	return 1;

}

int rowdfs(int curY, int curX,int same,char data)
{

	//same이 3으로 조건을 만족하는 경우
	if (same == 3)
	{
		ret = data;
		return 1;
	}


	//행로 이동
	int nextY = curY+1;
	int nextX = curX ;

	if (innerArea(nextY, nextX) == 0)
	{
		return 0;
	}

	if (map[nextY][nextX] == data)
	{
		return rowdfs(nextY, nextX, same + 1, data);
	}

	
	return 0;
}

int coldfs(int curY, int curX, int same, char data)
{

	//same이 3으로 조건을 만족하는 경우
	if (same == 3)
	{
		ret = data;
	//	printf("ret =%c\n", ret);
		return 1;
	}


	//열로 이동
	int nextY = curY;
	int nextX = curX+1 ;

	if (innerArea(nextY, nextX) == 0)
	{
		return 0;
	}

	if (map[nextY][nextX] == data)
	{
		return coldfs(nextY, nextX, same + 1, data);
	}


	return 0;
}
int diagdfs1(int curY, int curX, int same, char data) // 우하
{

	//same이 3으로 조건을 만족하는 경우
	if (same == 3)
	{
		ret = data;
		return 1;
	}


	//대각선으로 이동
	int nextY = curY + 1;
	int nextX = curX + 1;

	if (innerArea(nextY, nextX) == 0)
	{
		return 0;
	}

	if (map[nextY][nextX] == data)
	{
		return diagdfs1(nextY, nextX, same + 1, data);
	}


	return 0;
}

int diagdfs2(int curY, int curX, int same, char data) // 좌하
{

	//same이 3으로 조건을 만족하는 경우
	if (same == 3)
	{
		ret = data;
		return 1;
	}


	//대각선으로 이동
	int nextY = curY + 1;
	int nextX = curX - 1;

	if (innerArea(nextY, nextX) == 0)
	{
		return 0;
	}

	if (map[nextY][nextX] == data)
	{
		return diagdfs2(nextY, nextX, same + 1, data);
	}


	return 0;
}

int main()
{

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", map[i]);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == '.')
			{
				continue;
			}


			if (rowdfs(i, j, 1, map[i][j]) == 1)
			{
				//printf("진입\n");
				printf("%c\n", ret);

					return 0;
			}
			else if (coldfs(i, j, 1, map[i][j]) == 1)
			{
				printf("%c\n", ret);

					return 0;
			}
			else if (diagdfs1(i, j, 1, map[i][j])== 1)
			{
				printf("%c\n", ret);

				return 0;
			}
			else if (diagdfs2(i, j, 1, map[i][j]) == 1)
			{
				printf("%c\n", ret);

				return 0;
			}

		}
	}
	printf("ongoing\n");
	

	return 0;
}