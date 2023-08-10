/*
	1. 


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
