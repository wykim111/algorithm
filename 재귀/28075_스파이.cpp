/*
	중복 순열 알고리즘

	1.	인덱스 정의 
		1-1) "수족관"에서 정보 수집 - 0번쨰 인덱스
		1-2) "시청"에서 정보 수집 - 1번쨰 인덱스
		1-3) "학교"에서 정보 수집 - 2번쨰 인덱스
		1-4) "수족관"에서 감시 - 3번쨰 인덱스
		1-5) "시청"에서 감시 - 4번쨰 인덱스
		1-6) "학교"에서 감시 - 5번쨰 인덱스

	2. 0부터 5번쨰 인덱스를 이용하여 원소 N개를 구성하는 중복순열 경우의 수를 구함.

	3. 중복순열 경우의 수가 구성되면 M개 이상인지 카운트
		3-1) 3으로 나누어 나머지가 0이면 수족관
		3-2) 3으로 나누어 나머지가 1이면 시청
		3-3) 3으로 나누어 나머지가 2이면 학교
		3-4) 구성된 중복순열 길이 0부터 N-1까지 탐색
			3-4-1) i-1번째와 i번째 비교 시 장소가 같으면, 현재 i번째에 속하는 점수(정보 수집 혹은 감시)를 절반 카운트 
			3-4-2) i-1번째와 i번째 비교 시 장소가 다르면, 현재 i번째에 속하는 점수(정보 수집 혹은 감시)를 그대로 카운트
		3-5) 3-4)에서 구한 카운트가 M 이상이면 true 리턴


*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, M;
vector<int> perm;

vector<int> input_vt;

int answer = 0;

void input()
{
	
	cin >> N >> M;

	for (int i = 0; i < 3; i++)
	{
		int infomation;

		cin >> infomation;

		input_vt.push_back(infomation);
	}


	for (int i = 0; i < 3; i++)
	{
		int monitor;

		cin >> monitor;

		input_vt.push_back(monitor);
	}
}

int calculate()
{
	int sum = 0;

	for (int i = 0; i < perm.size(); i++)
	{
		if (i > 0)
		{
			int cur = (perm[i] % 3);
			int prev = (perm[i - 1] % 3);

			if (cur == prev)
			{
				sum += (input_vt[perm[i]] / 2);
			}
			else
			{
				sum += input_vt[perm[i]];
			}

		}
		else
		{
			sum += input_vt[perm[i]];
		}
	}

	if (sum >= M)
	{
		return true;
	}

	return false;
}

void go(int dep)
{
	if (dep == N)
	{
#if 0
		for (int i = 0; i < perm.size(); i++)
		{
			cout << perm[i] << ' ';
		}
		cout << '\n';
#endif

		if (calculate() == true)
		{
			++answer;
		}


		return;
	}

	for (int i = 0; i < 6; i++)
	{
		perm.push_back(i);
		go(dep + 1);
		perm.pop_back();
	}

}

void solution()
{
	go(0);

	cout << answer << '\n';
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
