/*	<LCS �˰���> -> ���̳��� ���α׷���
	1.���ϴ� ���ڿ��� ������ ���� �밢���� ������ +1
	2.���ϴ� ���ڿ��� �ٸ��� max(����,����)���� ����


	if(str1[i] == sr2[j] then dp[i-1][j-1] +1

	else
		max(dp[i][j-1],dp[i-1][j]);
		

*/

#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>

using namespace std;
int dp[1001][1001] = { 0, };
string str1, str2;

int main()
{
	int len1,len2;

	cin >> str1;
	cin >> str2;

	len1 = str1.length();
	len2 = str2.length();

	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (str1[i-1] == str2[j-1])
			{	//���� �밢���� ������
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{	//max(����,����) �� �� �ִ�
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	printf("%d\n", dp[len1][len2]);

	return 0;
}