#include<stdio.h>
#include<math.h>

char puzzle[5][5];

int posAbs(int a, int b)
{
	return a < b ? b - a : (a - b);
}

int main()
{
	int ret = 0;
	//input
	for (int i = 0; i < 5; i++)
	{
		scanf("%s", puzzle[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (puzzle[i][j] != '.')
			{
				ret += posAbs(i,(puzzle[i][j] - 'A') / 4) + posAbs((puzzle[i][j] - 'A') % 4,j);
			}
		}
	}
	printf("%d\n", ret);

	return 0;
}