/*
	< 그리디 알고리즘>

	1. i번째 날 최저가를 구함
		min_arr[i] = min(min_arr[i-1], A[i]);
	2. i번째 날 최대 수익
		2-1. 이전까지 최대수익과 오늘 팔았을떄의 수익 중 최댓값

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> A_vt;
vector<int> ans_vt;

void input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;

		cin >> num;

		A_vt.push_back(num);
	}
}

void solution()
{
	int max_ans = 0;

	for (int i = 0; i < N; i++)
	{
		
		for (int j = 0; j < i; j++)
		{
			max_ans = max(A_vt[i] - A_vt[j], max_ans);
		}

		ans_vt.push_back(max_ans);
	}

	for (int i = 0; i < ans_vt.size(); i++)
	{
		cout << ans_vt[i] << ' ';
	}
	cout << '\n';

}

int main()
{
	ios::sync_with_stdio(NULL);
	cout.tie(NULL);
	cin.tie(NULL);

	input();
	solution();

	return 0;
}