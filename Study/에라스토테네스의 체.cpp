/*
	소수 배열의 플래그가 1인 경우 소수가 아니고 0인 경우 소수이다
	0과 1은 플래그가 0이지만 소수가 아니다
*/

#include<stdio.h>
#include<math.h>

int prime[101] = { 0,0, };
int cnt = 0;

int main()
{
	for (int i = 2; i <= sqrt(100); i++)
	{
		for (int j = 2; i*j <= 100; j++)
		{
			//기존에 소수 아닌 플래그 체크 한 경우
			if (prime[i*j] == 1)
			{
				continue;
			}

			//소수가 아닌 경우 1로 설정
			prime[i*j] = 1;
		}
	}

	for (int i = 2; i <= 100; i++)
	{
		if (prime[i] == 1)//1인 경우 소수가 아님
			continue;
		printf("%d ", i);
		cnt++;
	}
	printf("\n");
	printf("카운트 = %d\n", cnt);

	return 0;
}