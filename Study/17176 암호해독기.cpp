/*
	0은 띄어쓰기, 1 - 26 범위 안의 수는 A ~ Z, 27 - 52 범위 안의 수는 a ~ z로 해석

	-> 배열 arr[53] 선언하여 0부터 52까지 위의 알파벳을 저장한다.
	-> 입력한 문자열과 숫자를 인덱스로 가진 데이터와 일치 여부를 파악
	-> 각 범위 구간마다 해당 데이터 플래그를 카운트하여 모두 2이면 다 있는 것이고 하나라도 1이면 일치하지 않은 것
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int N;
int script[53];
char str[100005];

int main()
{
	int len = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int num;

		scanf("%d", &num);

		script[num]++;
		//printf("num = %d\n", num);
	}
	while (getchar() != '\n');
	//문자열 입력
	fgets(str, sizeof(str), stdin);
	len = strlen(str);

	str[len - 1] = '\0';
	len = strlen(str);

	//암호문 플래그 카운트
	for (int i = 0; i < len; i++)
	{
		if (str[i] == ' ')
		{
			script[0]--;
		}
		else if ('A' <= str[i] && str[i] <= 'Z')
		{
			script[str[i] - 'A'+1]--;
		}
		else if ('a' <= str[i] && str[i] <= 'z')
		{
			script[str[i] - 'a' + 27]--;
		}
	}
	//카운트 플래그 중에 1이 있으면 암호화 할 수 없음
	for (int i = 0; i <= 52; i++)
	{
		if (script[i] != 0)
		{
			printf("n\n");
			return 0;
		}
	}
	
	printf("y\n");

	return 0;
}

