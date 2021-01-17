/*
	printf로 출력 포맷팅을 잘하자!
*/
#include<stdio.h>


int main()
{
	int tc;

	scanf("%d", &tc);

	while (tc--)
	{
		int num;
		int flag = 0;

		scanf("%d", &num);

		printf("Pairs for %d:", num);
		
		for (int i = 1; i < num; i++)
		{
			for (int j = i + 1;j < num; j++)
			{
				if ((i + j) == num && flag ==0)
				{
					flag = 1;
					printf(" %d %d", i, j);
				}
				else if((i+j) == num && flag == 1)
				{
					printf(", %d %d", i, j);
				}

			}//j
		}//i
		printf("\n");
	}

	return 0;
}