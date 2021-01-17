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
	//���ڿ� �� �� �ϳ��� �� Ž���� ���� ���
	if (len1 == 0 || len2 == 0)
	{
		return 0;
	}
	//���ڿ��� ���� ���
	if (X[len1 - 1] == Y[len2 - 1])
	{
		return 1 + LCS(len1 - 1, len2 - 1);
	}
	else
	{
		//���ڿ��� �ٸ� ���
		//���� ���ڿ��� ���� ���ڷ� �����ϰ� ������ ���ڿ��� ���� ������ �״�� ��
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