#include<stdio.h>

int chang = 100, sang = 100;
int N;
int dice1,dice2;

int main()
{
	scanf("%d", &N);

	while (N--)
	{
		//창영 상덕 순
		scanf("%d %d", &dice1, &dice2);
		//낮은 숫자가 나온 사람은 상대편 주사위에 나온 숫자만큼 점수를 잃게 된다.
		if (dice1 > dice2)
		{
			sang -= dice1;
		}
		else if(dice1 < dice2)
		{
			chang -= dice2;
		}
		else
		{
			//blank
		}

	}
	printf("%d\n%d\n", chang, sang);

	return 0;
}


