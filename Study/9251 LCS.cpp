/*	<LCS 알고리즘> -> 다이나믹 프로그래밍
	1.비교하는 문자열이 같으면 좌측 대각선의 데이터 +1
	2.비교하는 문자열이 다르면 max(왼쪽,윗쪽)으로 저장


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
			{	//좌측 대각선의 데이터
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{	//max(왼쪽,윗쪽) 둘 중 최댓값
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	printf("%d\n", dp[len1][len2]);

	return 0;
}
