#include<stdio.h>
#include<math.h>

int N;
int map[15];//인덱스는 Row를 의미, 해당하는 데이터는 Col을 의미
int sum = 0;

int threat(int Row)
{
	int cur_Row = 0;

	while (cur_Row < Row)
	{
		//대각선-> 좌측 대각선 및 우측 대각선
		//직선
		if (abs(cur_Row - Row) == abs(map[cur_Row] - map[Row]) ||((map[cur_Row]- map[Row])== 0) )
		{
			return 1;
		}
		cur_Row++;
	}
	return 0;
}

void find_Queen(int Row,int cnt)
{
	//퀸의 동선에 있는지 확인
	if (threat(Row) == 1)
	{
		return;
	}
	else if (Row == N-1)
	{
		sum++;
		return;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			map[Row + 1] = i;
			find_Queen(Row+1,cnt+1);
		}
	}
}


int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		map[0] = i;//0행에 해당하는 col을 대입
		find_Queen(0, 0);
	}
	printf("%d\n", sum);
	
	return 0;
}
