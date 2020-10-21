/*
	1. 문자열로 입력 -> 배열로 역순으로 저장
	2. 자릿수가 적은 문자열에는 숫자 이외 자리에 '0'으로 씌움
	3. 1의자리부터 계산하여  10이하이면 sum에 저장
	4. 10이상이면 carry가 발생하므로 carry = 1로 설정하고 10을 뺴서 일의자리를 sum에 저장

*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string str1, str2;
int a[10001], b[10001], sum[10001];

int main()
{
	int carry=0;
	int maxLen = 0;

	cin >> str1 >> str2;
	//역순으로 저장
	for (int i = 0; i < str1.length(); i++)
	{
		char ch = str1.at(i);
		a[str1.length() - i - 1] = atoi(&ch);
	}
	for (int i = 0; i < str2.length(); i++)
	{
		char ch = str2.at(i);
		b[str2.length() - i - 1] = atoi(&ch);
	}
	//가장 큰 자릿수 
	maxLen = max(str1.length(), str2.length());
	//연산
	for (int i = 0; i < maxLen; i++)
	{
		sum[i] = a[i] + b[i] + carry;

		if (sum[i] >= 10)
		{
			sum[i] -= 10;
			carry = 1;
		}
		else
		{
			carry = 0;
		}
	}
	if (carry == 1)
	{
		cout << 1; //마지막 가장 큰 자릿수에서 10이상이면 자릿수를 늘려야하므로
	}
	for (int i = 0; i < maxLen; i++)
	{
		cout << sum[maxLen - i - 1];
	}

	return 0;
}
