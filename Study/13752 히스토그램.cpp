#include<stdio.h>

int main()
{
	int n, k;

	scanf("%d", &n);

	while (n--)
	{
		scanf("%d", &k);

		for (int i = 0; i < k; i++)
		{
			printf("=");
		}
		printf("\n");
	}

	return 0;
}