/*
	등차수열의 일반항으로 해당 숫자가 몇번쨰 항인지 찾는 문제
	공차가 음수냐 양수냐에 따라 범위 조정이 관건

	공차가 양수인 경우 target보다 크면 벗어남
	공차가 음수인 경우 target보다 작으면 벗어남
*/
#include<stdio.h>

int  main()
{
	while (1)
	{
		int num1, num2, target;
		int an = 0, d = 0;
		int i = 1;

		scanf("%d %d %d", &num1, &num2, &target);

		if (num1 == 0 && num2 == 0 && target == 0)
			break;

		//공차
		d = num2;
		
		for (int i = 1;; i++)
		{
			an = num1 + ((i - 1)*d);

			//target의 범위가 벗어난 경우 (음수인 경우와 양수인 경우)
			if (d > 0 && an > target)
			{
				printf("X\n");
				break;
			}
			else if(d < 0 && an < target)
			{
				printf("X\n");
				break;
			}

			//target과 일치하는 경우
			if (target == an)
			{
				printf("%d\n", i);
				break;
			}
		}
	}

	return 0;
}