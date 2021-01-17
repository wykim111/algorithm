#include<stdio.h>
#include<string.h>

int customer[100][6];
int lotto[50];
int check()
{
	for (int i = 1; i <= 49; i++)
	{
		if (lotto[i] != 1)
		{
			return 0;
		}

	}

	return 1;
}

int main()
{
	int TC;

	while ((scanf("%d", &TC)) && (TC != 0))
	{
		
		
		memset(lotto, 0, sizeof(lotto));
		memset(customer, 0, sizeof(customer));
		for (int i = 0; i < TC; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				scanf("%d", &customer[i][j]);
				lotto[customer[i][j]] = 1;
			}
		}

		if (check() == 1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}


	}//while
}