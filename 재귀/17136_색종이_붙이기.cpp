/*
	- 1이 있는 면적의 종이에 해당하는 크기의 종이를 선택하여 붙임

*/
#include<iostream>
#include<algorithm>

using namespace std;

int ret = 987654321;
int paper[6] = { 0,5,5,5,5,5 };
int map[11][11];
int cnt = 0;

//1을 만나는 경우,
//0을 만나는 경우 다음 열로 이동
//열의 끝에 존재하는 경우 다음 행으로 이동
void dfs(int y, int x)
{
	if (x == 10)
	{
		dfs(y + 1, 0);
		return;
	}

	if (y == 10)
	{
		ret = min(ret, cnt);
		return;
	}

	if (map[y][x] == 0)
	{
		dfs(y, x + 1);
		return;
	}

	

	//모든 색종이의 사이즈를 덮어 봄
	for (int size = 1; size <= 5; size++)
	{
		//종이의 갯수가 없는 경우
		if (paper[size] == 0)
		{
			continue;
		}
		//맵의 범위를 벗어나는 경우
		if (y + size > 10 || x + size > 10)
		{
			continue;
		}

		int flag = 1;
		for (int h = 0; h < size; h++)
		{
			for (int w = 0; w < size; w++)
			{
				if (map[y + h][x + w] == 0)
				{
					flag = 0;
					break;
				}
			} // w

			if (flag == 0)
			{
				break;
			}

		} // h

		//해당 사이즈의 종이로 덮을 수 없는 경우
		//다음 사이즈의 종이로 넘어감
		if (flag == 0)
			continue;
		//flag == true로 덮을 수 있는 경우
		//0으로 설정
		for (int h = 0; h < size; h++)
		{
			for (int w = 0; w < size; w++)
			{
				map[y + h][x + w] = 0;
			} // w

		
		} // h
		paper[size]--;
		cnt++;

		dfs(y, x + size);

		//이미 사용한거 복원
		for (int h = 0; h < size; h++)
		{
			for (int w = 0; w < size; w++)
			{
				map[y + h][x + w] = 1;
			} // w


		} // h

		paper[size]++;
		cnt--;
	}//size


}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	dfs(0, 0);

	if (ret == 987654321)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", ret);
	}

	return 0;
}
