#include<stdio.h>
#include<string.h>

int tc;


int toBinary(int n)
{
	int idx = 0;

	while (n != 0)
	{
		int remain = n % 2;
		n = n / 2;
		idx++;
	}

	return idx;
}


int main()
{
	scanf("%d", &tc);

	while (tc--)
	{
		int num;
		int size = 0;

		scanf("%d", &num);

		size = toBinary(num);

		for (int digit = 0; digit < size; digit++)
		{
			if (num & (1 << digit))
			{
				printf("%d ", digit);
			}
		}
		printf("\n");

	}

	return 0;
}
