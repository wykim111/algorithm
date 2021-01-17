#include<stdio.h>

int main()
{
	int search;
	int carNumber[5];
	int cnt = 0;

	scanf("%d", &search);

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &carNumber[i]);

		if (search == carNumber[i])
		{
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}