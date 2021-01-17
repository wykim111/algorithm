
/*
	갈색이 0인 경우는 가로 세로 둘중하나는 2이하이다
	문제의 요지는 최소 3x3 그림 구조이므로 위의 경우 생갹 제외

	1)R+B로 더한다.
	2)더한 합을 최소 3부터 나눈다
	3)나누어 떨어지는 경우, 가로*세로를 하여 R+B와 같은지 확인
	4) 같은 경우 R과 B 입력 값과 위의 과정에 나온 Red와 Brown비교
	   Brown의 경우 길이-2를 하면 갯수가 나옴
	  만약, 두 수가 다르다면, 큰 수가 L이 되고 작은 수가 W이 된다. 항상 정답이 유일한 경우만 입력으로 주어진다.
*/
#include<stdio.h>

int R, B;
int sum = 0;
int L, W;


int isCheck(int a, int b)
{
	int brown = b - 2;
	int red = a * b;

	brown = (a - 2) * brown;
	red -= brown;

	if (red == R && brown == B)
	{
		return 1;
	}
	return 0;
}

int main()
{
	
	scanf("%d %d", &R, &B);

	sum = R + B;

	for (int i = 3;i<=sum; i++)
	{
		int j = sum / i;

		if (j <= 2)
			continue;

		if (i*j == sum)
		{
			if (isCheck(i, j) == 1)
			{
				if (i < j)
				{
					L = j;
					W = i;

				}
				else
				{
					L = i;
					W = j;
				}
				break;
			}
		}
	}

	printf("%d %d\n", L, W);

	return 0;
}