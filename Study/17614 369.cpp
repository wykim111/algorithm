/*
	10으로 나누어서 나머지가 3,6,9가 있으면 카운트
	33 36 과 같이 벌칙으로 받아야 할 수가 다수 포함되면 포함된 수만큼 박수
*/

#include<stdio.h>

int main()
{
	int N;
	int cnt = 0;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		int temp = i;

		while (temp)
		{
			int num = i;
			int remainder = temp % 10;
			temp = temp / 10;

			if ((remainder  == 3) || (remainder  == 6) || (remainder  == 9))
			{
				//printf("num = %d\n", num);
				cnt++;
				
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}