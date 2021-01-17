/*
	•바위는 가위를 이긴다.
	•가위는 보를 이긴다.
	•보는 바위를 이긴다

	R, P, S는 순서대로 바위, 보, 가위이고 첫 번째 문자는 Player 1의 선택, 두 번째 문자는 Player 2의 선택이다.




출력

*/
#include<stdio.h>


int tc;

int main()
{
	scanf("%d", &tc);

	while (tc--)
	{
		int n;
		char player1 = 0, player2 = 0;
		int point1 = 0, point2 = 0;

		scanf("%d", &n);
		while (getchar() != '\n');

		while (n--)
		{
			scanf("%c %c", &player1, &player2);

			while (getchar() != '\n');
			
			if ((player1 == 'R' && player2 == 'S') || (player1 == 'S' && player2 == 'R'))
			{
				if (player1 == 'R')
					point1++;
				else if (player1 == 'S')
					point2++;
			}
			else if ((player1 == 'S' && player2 == 'P') || (player1 == 'P' && player2 == 'S'))
			{
				if (player1 == 'S')
					point1++;
				else if (player1 == 'P')
					point2++;
			}
			else if ((player1 == 'P' && player2 == 'R') || (player1 == 'R' && player2 == 'P'))
			{
				if (player1 == 'P')
					point1++;
				else if (player1 == 'R')
					point2++;
			}
		}//while n
		if (point1 > point2)
		{
			printf("Player 1\n");
		}
		else if (point1 < point2)
		{
			printf("Player 2\n");
		}
		else
		{
			printf("TIE\n");
		}

	}//while tc

	return 0;
}