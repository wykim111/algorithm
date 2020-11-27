/*
보통 큰 숫자를 왼쪽에 작은 숫자를 오른쪽에 쓴다. 그리고 그 값은 모든 숫자의 값을 더한 값이 된다. 예를 들어 LX = 50 + 10 = 60 이 되고, MLI = 1000 + 50 + 1 = 1051 이 된다.
V, L, D는 한 번만 사용할 수 있고 I, X, C, M은 연속해서 세 번까지만 사용할 수 있다. 예를 들어 VV나 LXIIII 와 같은 수는 없다. 그리고 같은 숫자가 반복되면 그 값은 모든 숫자의 값을 더한 값이 된다. 예를 들어 XXX = 10 + 10 + 10 = 30 이 되고, CCLIII = 100 + 100 + 50 + 1 + 1 + 1 = 253 이 된다.
작은 숫자가 큰 숫자의 왼쪽에 오는 경우는 다음과 같다. 
IV = 4, IX = 9, XL = 40, XC = 90, CD = 400, CM = 900 을 나타낸다. 
이들 각각은 한 번씩만 사용할 수 있다. 그런데 IV 와 IX 는 같이 쓸 수 없으며 XL 과 XC, CD 와 CM 또한 같이 쓸 수 없다. 이들 외에는 작은 숫자가 큰 숫자 왼쪽 어디에도 나올 수 없다. 예를 들어 XCXC 나 CMCD, VX 나 IIX 와 같은 수는 없다. 
참고로 LIX = 50 + 9 = 59, CXC = 100 + 90 = 190 이 된다.
모든 수는 가능한 가장 적은 개수의 로마 숫자들로 표현해야 한다. 
예를 들어 60 은 LX 이지 XLXX 가 아니고, 5 는 V 이지 IVI 가 아니다.

*/

#include<stdio.h>
#include<string.h>

int romeNum[10001];

char str1[2001];
char str2[2001];
char str3[4002];
int idx = 0;

int main()
{
	int len1 = 0, len2 = 0;
	int sum1 = 0, sum2 = 0;
	int sameFlag = 0;

	scanf("%s", str1);
	scanf("%s", str2);

	romeNum['I'] = 1;
	romeNum['V'] = 5;
	romeNum['X'] = 10;
	romeNum['L'] = 50;
	romeNum['C'] = 100;
	romeNum['D'] = 500;
	romeNum['M'] = 1000;

	len1 = strlen(str1);

	for (int i = 0; i < len1; i++)
	{
		if (i<len1-1 && romeNum[str1[i]] > romeNum[str1[i + 1]])
		{
			sum1 += romeNum[str1[i]];
			
		}
		else if (i<len1-1 && romeNum[str1[i]] < romeNum[str1[i + 1]])
		{
			sum1 += romeNum[str1[i + 1]] - romeNum[str1[i]];
			i++;
		}
		else
		{
			//i다음인 i+1데이터도 연산해야함
			sum1 += romeNum[str1[i]];
			sameFlag++;
		}
	}

	len2 = strlen(str2);
	sameFlag = 0;

	for (int i = 0; i < len2; i++)
	{
		if (i < len2-1 && romeNum[str2[i]] > romeNum[str2[i + 1]])
		{
			sum2 += romeNum[str2[i]];
			
		}
		else if (i < len2-1 &&romeNum[str2[i]] < romeNum[str2[i + 1]])
		{
			sum2 += romeNum[str2[i + 1]] - romeNum[str2[i]];
			i++;
		}
		else
		{
			sum2 += romeNum[str2[i]];
			sameFlag++;
		}
	}
	int temp = sum1 + sum2;

	printf("%d\n", sum1 + sum2);

	while (temp != 0)
	{
		if (temp >= 1000)
		{
			printf("M");
			temp -= 1000;
		}
		else if (temp >= 900)
		{
			printf("CM");
			temp -= 900;
		}
		else if (temp >= 500)
		{
			printf("D");
			temp -= 500;
		}
		else if (temp >= 400)
		{
			printf("CD");
			temp -= 400;
		}
		else if (temp >= 100)
		{
			printf("C");
			temp -= 100;
		}
		else if(temp >= 90)
		{
			printf("XC");
			temp -= 90;
		}
		else if (temp >= 50)
		{
			printf("L");
			temp -= 50;
		}
		else if (temp >= 40)
		{
			printf("XL");
			temp -= 40;
		}
		else if (temp >= 10)
		{
			printf("X");
			temp -= 10;
		}
		else if (temp >= 9)
		{
			printf("IX");
			temp -= 9;
		}
		else if (temp >= 5)
		{
			printf("V");
			temp -= 5;
		}
		else if (temp >= 4)
		{
			printf("IV");
			temp -= 4;
		}
		else if (temp >= 1)
		{
			printf("I");
			temp -= 1;
		}
		else
		{
			//skip
		}
	}


	
	return 0;
}
