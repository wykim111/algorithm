#include<stdio.h>

int N;
char op[12][12];

void backtrack(int dep)
{

}
int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		for (int j = i; j <= N; j++)
		{
			scanf("%1c", &op[i][j]);
		}
	}
	backtrack(1);
}