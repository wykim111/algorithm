/*
	1. N의 자릿수 길이를 구한다
	2. 자릿수 -1을 하여 자릿수-1에 해당하는 갯수 * 자릿수-1을 한다.
	3. 자릿수가 0이 될 때까지 반복
	ex) 123 이면 3자리 이므로 3-1 = 2, 2자리 10 부터 99까지 90개와
	    공통적인 자릿수는 2이므로 2*90 연산
		1은 1부터 9까지로 위의 수에 1*9 연산
		0이되면 끝

		해당자리수의 경우 123 - 100+1 = 24(0부터 23) * 3(자릿수)로 연산 

	
	*/

#include <stdio.h>
#include <math.h>

int getDigit(int num)
{
	int len = 0;
	while (num != 0)
	{
		num = num / 10;
		len++;
	}

	return len;
}


int main()
{
	int N;
	int digit = 0;
	long long cnt = 0;

	scanf("%d", &N);

	digit = getDigit(N);

	
	//N의 기준점을 구함 
	//123이면 100이 기준, 1234이면 1000이 기준
	cnt =(long long) N - (long long)pow(10, digit - 1)+1;//+1은 자기 자신 포함
	cnt = (long long)cnt * digit;

	int  tempDigit = digit-1;

	
	while (tempDigit > 0)
	{
		if (tempDigit == 8)
		{
			cnt += 8 * 90000000;
		}
		else if (tempDigit == 7)
		{
			cnt += 7 * 9000000;
		}
		else if (tempDigit == 6)
		{
			cnt += 6 * 900000;
		}
		else if (tempDigit == 5)
		{
			cnt += 5 * 90000;
		}
		else if (tempDigit == 4)
		{
			cnt += 4 * 9000;
		}
		else if (tempDigit == 3)
		{
			cnt += 3 * 900;
		}
		else if (tempDigit == 2)
		{
			cnt += 2 * 90;
		}
		else if (tempDigit == 1)
		{
			cnt += 1 * 9;
		}
		tempDigit--;
	}

	printf("%lld\n", cnt);

	return 0;
}
