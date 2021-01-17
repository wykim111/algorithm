/*
	입력한 분에 -45를 하여 0보다 작은 경우
	hour을 -1 하며, 0보다 작은 값만큼 60에서 弧娩.
*/

#include<stdio.h>

int H, M;

int main()
{
	scanf("%d %d", &H, &M);

	if (M - 45 < 0)
	{
		int temp = M - 45;//음수
		M = 60 + temp;
		H -= 1;

		if (H < 0)
		{
			H = 23;
		}
	}
	else
	{
		M -= 45;

	}

	printf("%d %d\n", H, M);

	return 0;
}
