#include<stdio.h>

int N;
int bar[100000];

int main()
{
	int cnt = 0;
	int std = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &bar[i]);
	}

	for (int i = N-1; i >= 0; i--)
	{
		//지금 보이는 막대기보다 뒤에 있고 높이가 높은 것이 보이게 되므로 기준 높이 업데이트
		if (std < bar[i])
		{
			std = bar[i];
			cnt++;
		
		}
	}

	printf("%d\n", cnt);

	return 0;
}