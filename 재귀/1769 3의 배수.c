/* 

풀고자 하는 문제를 다른 문제로 변환한다.(재귀)
변환된 문제의 답을 구한다.
구한 답을 원래 문제의 답으로 삼는다.

ex) 
1234567 -> 28 -> 10 -> 1 (NO)

1. 각 자릿수를 더하여 해당 숫자가 일의자리가 아니면 다시 각 자릿수를 더한다.
2. 한자리만 남은 경우 3의 배수인지 확인
3  0부터 9까지 한자리 입력인 경우 예외 처리
*/
#include<stdio.h>
#include<string.h>

char str[1000002];

int go(int idx, int sum)
{
	if (idx == -1)
	{
		return sum;
	}

	return go(idx - 1, sum + (str[idx] - '0'));
}

void intToString(int n)
{
	int idx = 0;
	int size = 0;

	while (n != 0)
	{
		int remain = n % 10;
		str[idx++] = remain + '0';
		n /= 10;
	}
	str[idx] = '\0';
	
	size = idx;
	//reverse
	for (int i = 0; i < size / 2; i++)
	{
		char temp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = temp;
	}
}

int main()
{
	int cnt = 0,num = 0;
	int len = 0;

	scanf("%s", str);
	len = strlen(str);

	if (len == 1)
	{
		num = str[0] - '0';
	}
	else
	{
		while (len > 1)
		{
			num = go(len - 1, 0);
		//	printf("num = %d\n", num);
			memset(str, 0, sizeof(str));
			//숫자를 다시 문자열에 넣어줌
			intToString(num);

			len = strlen(str);
			cnt++;
		}
	}
	if (num % 3 == 0)
	{
		printf("%d\nYES\n", cnt);
	}
	else
	{
		printf("%d\nNO\n", cnt);
	}

	return 0;
}
