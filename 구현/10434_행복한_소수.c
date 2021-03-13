/*
1. 문자열 입력
  - 소수 판별 
  1) 2부터 해당숫자-1까지 나누어 떨어지지 않으면 소수, 나누어 떨어지면 소수가 아님
2. 문자열의 길이만큼 데이터를 숫자로 파싱하여 숫자 제곱 연산
3. 연산한 숫자가 cycle처럼 기존에 체크한 숫자인지 판별
	- 기존에 체크한 숫자라면 false 리턴
	- 새 숫자라면 1로 저장
	- 연산한 숫자가 1이 되면 true 리턴



테스트 케이스의 번호, 
입력받은 수, 만일 M이 행복한 소수라면 YES 아니라면 NO를 공백으로 각각 구분
*/

#include<stdio.h>
#include<string.h>
#include<math.h>

int P, m;
char str[10];
int tc;
int num = 0;

int checkPrime(int num)
{
	
	if (num == 1)
		return 0;

	for (int i = 2; i < num; i++)
	{
		if (num%i == 0)
		{
			return 0;
		}
	}

	return 1;
}

int checkHappy(int n)
{
	int check[1000];
	int temp = n;

	memset(check, 0, sizeof(check));
	if (checkPrime(temp) == 0)
		return 0;

	int sum = 0;
	while (1)
	{
		sum = 0;

		if (temp == 1)
			return 1;
		while (temp > 0)
		{
			sum += (int)pow(temp%10, 2);
			temp /= 10;
		}

		//Cycle 체크
		if (check[sum] == 1)
		{
			return 0;
		}
		check[sum] = 1;
		temp = sum;

	}

	return 1;
}

int main()
{
	
	scanf("%d", &P);

	while (P--)
	{
		scanf("%d %d", &tc, &num);

	
		if (checkHappy(num) == 1)
		{
			printf("%d %d YES\n", tc, num);
		}
		else
		{
			printf("%d %d NO\n", tc, num);
		}

	}//while P

	return 0;
}
