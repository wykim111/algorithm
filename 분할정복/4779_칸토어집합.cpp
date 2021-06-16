/*
	go(시작점, 시작점부터 (사이즈/3 - 1))
	blank(시작점+(사이즈/3), 시작점+(사이즈/3) + size-1
	go(시작점+(사이즈/3)*2, 시작점+(사이즈/3)*2 +size-1)
*/

#include<stdio.h>
#include<string.h>
#include<math.h>

char str[531441];
int N;
int len = 0;

void blank(int left, int right)
{
	for (int i = left; i <= right; i++)
	{
		str[i] = ' ';

	}

}


void go(int dep, int left, int right, int size)
{
	if (dep == 0)
	{

		return;
	}

	go(dep - 1, left, left + (size / 3) - 1, size / 3);
	blank(left + ((size / 3)), left + ((size / 3)) + (size / 3) - 1);
	go(dep - 1, left + ((size / 3) * 2), left + ((size / 3) * 2) + (size / 3) - 1, size / 3);

}

int main()
{
	while (scanf("%d", &N) != EOF)
	{
		memset(str, 0, sizeof(str));

		if (N == 0)
		{
			printf("-\n");

			continue;
		}

		for (int i = 0; i < (int)pow(3, N); i++)
		{
			str[i] = '-';
		}

		//printf("%s\n",str);

		len = strlen(str);

		go(N, 0, len - 1, len);

		printf("%s\n", str);
	}
	return 0;
}
