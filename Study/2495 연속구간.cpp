/*
	���� ���� ��Ƽ� �� ���� �ٸ��� ���ذ��� ������Ʈ �ϰ� ��
*/
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char str[3][9] = { 0 };

int cnt(int dep)
{
	int cnt = 1;
	int maxRet = 1;
	char standard = str[dep][0];

	for (int i = 1; i < 9; i++)
	{
		if (str[dep][i] == standard)
		{
			cnt++;
		}
		else
		{
			if (maxRet < cnt)
			{
				maxRet = cnt;
			}

			standard = str[dep][i];
			cnt = 1;
		}
	}
	return maxRet;
}

int main()
{
	for (int i = 0; i < 3; i++)
	{
		scanf("%s", str[i]);
		printf("%d\n", cnt(i));
	}
	return 0;
}