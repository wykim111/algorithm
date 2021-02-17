/*
  https://programmers.co.kr/learn/courses/30/lessons/42889
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cntUser[502];
vector < pair < double, int>> rateFail;//실패율, 스테이지

bool cmp(pair<double,int> n1, pair<double, int> n2)
{
	//만약 실패율이 같은 스테이지가 있다면 
	//작은 번호의 스테이지가 먼저 오도록 하면 된다
	if (n1.first == n2.first)
	{
		return n1.second < n2.second;
	}

	return n1.first > n2.first; 
}

vector<int> solution(int N, vector<int> stages) {
	
	int person = stages.size();
	vector<int> answer;

	for (vector<int>::iterator iter = stages.begin(); iter != stages.end(); iter++)
	{
		cntUser[*iter-1]++;
	}
	
	for (int i = 0; i < N; i++)
	{
		if (cntUser[i] == 0)
		{
			rateFail.push_back(make_pair(0, i + 1));
		}
		else
		{
			rateFail.push_back(make_pair((double)cntUser[i]/person, i + 1));
			person -= cntUser[i];
		}

		
	}
	sort(rateFail.begin(), rateFail.end(), cmp);

	for (int i = 0; i < N; i++)
	{
		answer.push_back(rateFail[i].second);
	}

	return answer;
}

int main()
{
	int N;
	vector<int>vt;
	cin >> N;

	for (int i = 0; i < 8; i++)
	{
		int num;

		cin >> num;
		vt.push_back(num);

	}

	solution(N, vt);


	return 0;
}
