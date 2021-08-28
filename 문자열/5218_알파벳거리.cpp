#include<stdio.h>
#include<string.h>

char str1[21], str2[21];

int main()
{
	int T;
	
	scanf("%d", &T);

	while (T--)
	{
		int len = 0;
		int dist[21];

		memset(str1, 0, sizeof(str1));
		memset(str2, 0, sizeof(str2));
		memset(dist, 0, sizeof(dist) / sizeof(int));

		scanf("%s %s", str1, str2);

		len = strlen(str1);
		/*
		  str2[idx] ≥ str1[idx]인 경우에는 y-x, y < x인 경우에는 (y+26) - x가 알파벳 거리가 된다.
		*/
		for (int i = 0; i < len; i++)
		{
			if (str1[i] <= str2[i])
			{
				dist[i] = (str2[i] - str1[i]);
			}
			else
			{
				dist[i] = ((str2[i]+26) - str1[i]);
			}
		}
		printf("Distances: ");
		for (int i = 0; i < len; i++)
		{
			printf("%d ", dist[i]);
		}
		printf("\n");

	}

	return 0;
}
