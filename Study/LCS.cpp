#include<stdio.h>
#include<string.h>

char X[100];
char Y[100];

int max(int n1, int n2)
{
	if (n1 > n2)
		return n1;

	return n2;
}

int LCS(int len1, int len2)
{
	//문자열 둘 중 하나가 다 탐색이 끝난 경우
	if (len1 == 0 || len2 == 0)
	{
		return 0;
	}
	//문자열이 같은 경우
	if (X[len1 - 1] == Y[len2 - 1])
	{
		return 1 + LCS(len1 - 1, len2 - 1);
	}
	else
	{
		//문자열이 다른 경우
		//한쪽 문자열을 다음 문자로 진행하고 나머지 문자열은 현재 포지션 그대로 둠
		return max(LCS(len1 - 1, len2), LCS(len1, len2 - 1));
	
	}
}

int main()
{
	int len1 = 0, len2 = 0;
	
	scanf("%s", X);
	scanf("%s", Y);

	len1 = strlen(X);
	len2 = strlen(Y);

	printf("%d\n",LCS(len1,len2));

	return 0;
}