/*
	KMP 알고리즘 개념

	- 접두사와 접미사가 같은게 몇 번 오는지 체크하여 Failure 함수에 적용

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
//dest문자열에 src와 같은 접두사, 접미사가 있는지 반복되는 길이 인덱스 체크
string T, P;
vector<int> ret;


vector<int> Failure(const string& s)
{
	vector<int> table(s.size());

	//반복되는 문자열 체크
	int j = 0;
	for (int i = 1; i < s.size(); i++)
	{
		while (j > 0 && s[j] != s[i])
		{
			j = table[j - 1];
		}
		//문자가 같은 경우
		if (s[i] == s[j])
		{
			table[i] = ++j;//j+1이 아닌 j = j+1로 해야함
		}
	}

	return table;
}

int main()
{


	getline(cin, T);
	getline(cin, P);

	vector<int> f = Failure(P);

	int j = 0;
	for (int i = 0; i < T.size(); i++)
	{
		while (j > 0 && T[i] != P[j])
		{
			j = f[j-1];
		}

		if (T[i] == P[j])
		{
			j++;
		}
		//j로 겹치는 문자 카운팅하며 탐색하다
		//문자열과 모두 일치하는 경우
		if (j == P.size())
		{
			ret.push_back(i-P.size()+2);
			j = f[j - 1];
		}
	}

	printf("%d\n", ret.size());

	for (int i = 0; i < ret.size(); i++)
	{
		printf("%d ", ret[i]);
	}
	printf("\n");


	return 0;
}
