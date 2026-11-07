/*
	< 문자열 >

	1. 입력된 각 알파벳 중 타겟 알파벳이 존재하면 카운트
	2, 입력된 각 알파벳이 타겟 문자열과 모두 매칭 되면, search_target_flag를 true로 설정
	3. search_target_flag를 true인 경우, target 알파벳의 최소 갯수가 곧 완성된 문자열ㄹ의 최대 갯수

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N;
string S;
string target_str = "HIARC";
int alphabet[26];


void input()
{
	cin >> N;
	cin >> S;
}

void solution()
{
	int ans = 0;
	bool search_flag = false;

	//각 알파벳 카운트
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == 'H' || S[i] == 'I'
			|| S[i] == 'A' || S[i] == 'R'
			|| S[i] == 'C')
		{
			++alphabet[S[i] - 'A'];
		}
	}

	if (alphabet['H' - 'A'] > 0 && alphabet['I' - 'A'] > 0 &&
		alphabet['A' - 'A'] > 0 && alphabet['R' - 'A'] > 0 && alphabet['C' - 'A'] > 0)
	{
		search_flag = true;
	}

	if (search_flag == true)
	{
		//최솟값 갱신
		ans = min({ alphabet['H' - 'A'],
					alphabet['I' - 'A'],
					alphabet['A' - 'A'],
					alphabet['R' - 'A'],
					alphabet['C' - 'A'] });
		
	}

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
