/*
가장 왼쪽 위칸의 색은 검정색이고, 나머지 색은 검정과 흰색이 번갈아가면서 등장한다. 검정색은 'X'로, 흰색은 '.'로 표시한다.
상근이의 체스판은 R행 * C열로 이루어져 있어야 한다. 또, 각각의 행의 높이는 문자 A개만큼 이며, 각각의 열의 너비는 문자 B개 만큼이다

1. A행 B열로 이루어진 문자열을 저장
2. R 그룹행에 0부터 A-1행까지 C그룹 열에서 B만큼 출력
	- 그룹 열이 짝수이면 'X; 홀수이면 '.'
*/
#include <stdio.h>
#include <string.h>

char black[11][11];
char white[11][11];
int R, C;
int A, B;
char board[101][101];
int col_index = 0;
int row_index = 0;


void get_board()
{
	for (int group_row = 0; group_row < R; group_row++)
	{
		if ((group_row % 2) == 0)
		{
			for (int row = 0; row < A; row++)
			{
				for (int group_col = 0; group_col < C; group_col++)
				{
					for (int col = 0; col < B; col++)
					{
						if ((group_col % 2) == 0)
						{
							printf("X");
						}
						else
						{
							printf(".");
						}
					}
				}//group_col
				printf("\n");
			}
		}
		else
		{
			for (int row = 0; row < A; row++)
			{
				for (int group_col = 0; group_col < C; group_col++)
				{
					for (int col = 0; col < B; col++)
					{
						if ((group_col % 2) == 0)
						{
							printf(".");
						}
						else
						{
							printf("X");
						}
					}
				}//group_col
				printf("\n");
			}
		}
	}//group_row
}

int main()
{
	scanf("%d %d", &R, &C);
	scanf("%d %d", &A, &B);

	get_board();

	return 0;
}
