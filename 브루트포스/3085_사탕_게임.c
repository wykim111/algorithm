/*
 빨간색은 C, 파란색은 P, 초록색은 Z, 노란색은 Y
  - 모두 같은 색으로 이루어져 있는 가장 긴 연속 부분(행 또는 열)을 고른 다음 그 사탕을 모두 먹는다.
 1. 맵에 동서남북 있는 데이터 차례대로 swap
 2. (0,0)부터 동서남북 순으로 탐색하여 같은 데이터 체크
 3. 현재 데이터를 기준으로 (왼쪽,오른쪽) 혹은 (위,아래) 체크하며 서로 다른 데이터가 있으면 체크 중단

*/

#include<stdio.h>

int N;
char map[51][51];
char copyMap[51][51];
int maxCnt = 0;

int max(int n1, int n2)
{
	if (n1 > n2)
		return n1;
	return n2;
}


void init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			copyMap[i][j] = 0;
		}
	}
}


void copy()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			copyMap[i][j] = map[i][j];
		}
	}
}

void swap(int pos1,int pos2, int dir)
{
	if (dir == 1 && pos2+1 < N)//동쪽과 교환
	{
		char temp = map[pos1][pos2];
		map[pos1][pos2] = map[pos1][pos2 + 1];
		map[pos1][pos2 + 1] = temp;
	}

	if (dir == 2 && pos2 -1 >=0)//서쪽과 교환
	{
		char temp = map[pos1][pos2];
		map[pos1][pos2] = map[pos1][pos2 - 1];
		map[pos1][pos2 - 1] = temp;
	}

	if (dir == 3 && pos1 +1 < N)//아래쪽과 교환
	{
		char temp = map[pos1][pos2];
		map[pos1][pos2] = map[pos1+1][pos2];
		map[pos1+1][pos2] = temp;
	}

	if (dir == 4 && pos1-1 >= 0)//북쪽과 교환
	{
		char temp = map[pos1][pos2];
		map[pos1][pos2] = map[pos1 - 1][pos2];
		map[pos1 - 1][pos2] = temp;
	}
} 


void check(int curY, int curX, int data)
{
	int cnt = 1;
	
	//위 아래 검사
	for (int nextY = curY-1; nextY >= 0; nextY--)
	{
		if (map[nextY][curX] != data)
		{
			break;
		}

		cnt++;
	}
	for (int nextY = curY+1; nextY < N; nextY++)
	{
		if (map[nextY][curX] != data)
		{
			break;
		}
		cnt++;
	}

	maxCnt = max(maxCnt, cnt);

	//좌우 검사
	cnt = 1;

	//좌우 검사
	for (int nextX = curX - 1; nextX >= 0; nextX--)
	{
		if (map[curY][nextX] != data)
		{
			break;
		}

		cnt++;
	}
	for (int nextX = curX + 1; nextX < N; nextX++)
	{
		if (map[curY][nextX] != data)
		{
			break;
		}

		cnt++;
	}
	maxCnt = max(maxCnt, cnt);

}


void Process(int curY,int curX)
{
	//동쪽과 바꿈
	swap(curY, curX,1);
	
	//동서남북 순으로 체크
	check(curY, curX,map[curY][curX]);
	
	//다시 원래대로 조정
	swap(curY, curX,1);

	//서쪽과 바꿈
	swap(curY, curX, 2);

	//동서남북 순으로 체크
	check(curY, curX, map[curY][curX]);

	//다시 원래대로 조정
	swap(curY, curX, 2);


	//남쪽과 바꿈
	swap(curY, curX, 3);
	
	//동서남북 순으로 체크
	check(curY, curX, map[curY][curX]);
	
	//다시 원래대로 조정
	swap(curY, curX,3);

	//북쪽과 바꿈
	swap(curY, curX, 4);

	//동서남북 순으로 체크
	check(curY, curX, map[curY][curX]);

	//다시 원래대로 조정
	swap(curY, curX, 4);
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
			Process(i,j);
		}
	}

	printf("%d\n", maxCnt);


	return 0;
}
