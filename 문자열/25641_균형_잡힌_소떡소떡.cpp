/*
	< 재귀, 문자열 >

	1. 탐색
		go(idx)
		{
			if(현재 구성된 문자열 균형이 이룬 경우)
			{
				//추출된 문자열 출력.
				return;
			}

			
			go(idx+1, input_str.substr(idx+1));
			
		}
	

*/


#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N;
string input_str;
string ans;

void input()
{
	cin >> N;
	cin >> input_str;
}

bool balance_ok(string& str)
{
	int s_count = 0;
	int t_count = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 's')
		{
			++s_count;
		}
		else if (str[i] == 't')
		{
			++t_count;
		}
	}

	if (s_count != t_count)
	{
		return false;
	}

	return true;
}

void go(int idx, string str)
{
	//cout << "str = " << str << '\n';
	
	if (idx >= N)
	{
		return;
	}
	if (balance_ok(str) == true)
	{
		
		ans = str;

		return;
	}

	go(idx + 1, input_str.substr(idx + 1));

}

void solution()
{
	go(0, input_str);

	cout << ans << '\n';

}


int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}