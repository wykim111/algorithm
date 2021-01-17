#include<stdio.h>

int main()
{
	int tournament[100001];
	int kim, lim;
	int N;
	int count = 0;
	scanf("%d %d %d", &N, &kim, &lim);

	if (N < kim || N < lim)
	{
		printf("-1\n");
		return 0;
	}

	while (kim != lim)
	{
		kim = kim / 2 + kim % 2;
		lim = lim / 2 + lim % 2;
	
		count++;
	}
	printf("%d\n", count);

	return 0;
}