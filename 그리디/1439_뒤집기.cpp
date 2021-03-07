/*
	-S에서 연속된 하나 이상의 숫자를 잡고 모두 뒤집는 것
		1. 0의 갯수 카운트
		2. 1의 갯수 카운트
		3. 1,2번중 가장  작은 숫자의 

		투 포인터 :left와 right를 두고 연속되는 범위 지정하여 카운트(1,2)
*/

#include<stdio.h>
#include<string.h>

char str[1000000];

int min(int n1, int n2)
{
	if (n1 > n2)
	{
		return n2;
	}

	return n1;
}

int main()
{
	int len = 0;

	scanf("%s", str);

	len = strlen(str);
	
	int left = 0, right = 0;
	int zeroCnt = 0;
	int oneCnt = 0;

	//0을 찾음
	for (left = 0; left < len; left++)
	{
		right = left;
		if (str[left] == '0')
		{
			while(str[left] == str[right])
			{
				right++;
			}
			zeroCnt++;
			left = right - 1;//for문의 left++로 right 가르킴
		}
	}
	//1을 찾음
	for (left = 0; left < len; left++)
	{
		right = left;
		if (str[left] == '1')
		{
			while (str[left] == str[right])
			{
				right++;
			}
			oneCnt++;
			left = right - 1;//for문의 left++로 right 가르킴
		}
	}
	//printf("zeroCnt = %d oneCnt = %d\n", zeroCnt, oneCnt);

	printf("%d\n", min(zeroCnt, oneCnt));

	return 0;
}
