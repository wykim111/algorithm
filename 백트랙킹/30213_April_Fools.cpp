/*
   <백트래킹 - subset , bitmasking>

   1. N개의 서로 다른 신문사가 보도한 사실들의 목록이 주어집니다. 각 사실은 1부터 F까지의 자연수로 나타냅니다.
   2. 당신은 이번 만우절에 각 신문사가 정확히 하나의 거짓 사실을 보도했다는 것을 알고 있습니다.
   3. 오늘 보도되었을 수 있는 전체 거짓 사실 개수의 최솟값과 최댓값을 구하십시오.

   ================================================================================================================
   1. 신문사 개수 N과 사실 개수 F를 입력받는다.
   2. 각 신문사가 보도한 사실들을 입력받는다.
   3. 전체 집합에 각 신문사가 보도한 사실들을 추가한다.
   4. 백트래킹 탐색.
	  go(int dep, int false_topic_subset)
	  {
		 if(dep == F)
		 {
			for(int i=0;i<N;i++)
			{
			   if (신문사 i가 보도한 사실들 중 false_topic_subset에 포함된 사실이 없다면)
			   {
				  return;
			   }

			   // false_topic_subset에 포함된 사실이 1개인 경우, false_topic_subset의 크기를 갱신한다.
			}

			return;
		 }

		 //가지치기
		 false_topic_subet |= (1 << dep);
		 is_proceed = true

		 for(신문사 순회)
			 if(신문사 i가 보도한 사실들 중 false_topic_subset에 포함된 사실이 2개 이상이라면)
			 {
				false_topic_subset &= ~(1 << dep);
				is_proceed = false
				return;
			 }
		if(is_proceed == false)
		 {
			 //현재 토픽 기사를 거짓으로 추가한 경우,
			 go(dep+1, false_topic_subset);
			 false_topic_subset &= ~(1 << dep);
		}

		 //현재 토픽 기사를 거짓으로 추가하지 않은 경우,
		 go(dep+1, false_topic_subset);

	  }


*/

#include <iostream>
#include <algorithm>
#include <vector>

#include <climits>
//#include <intrin.h>

//#define popcount __builtin_popcount

using namespace std;

int N, F;
unsigned int newspaper[201];
int min_ans = INT_MAX;
int max_ans = INT_MIN;

void input()
{
	cin >> N >> F;

	for (int i = 0; i < N; i++)
	{
		int topic_cnt;

		cin >> topic_cnt;

		for (int j = 0; j < topic_cnt; j++)
		{
			int topic_num;

			cin >> topic_num;

			newspaper[i] |= (1 << topic_num);
		}
	}
}

void go(int dep, int cur_topic, unsigned int false_topic_subset)
{
	if (dep == F)
	{
		//신문사들이 게시한 토픽들 중 거짓 토픽이 최소  1개 있어야 하는데 없는 경우,
		for (int i = 0; i < N; i++)
		{
#if 0
			if ((popcount(false_topic_subset & newspaper[i]) == 0))
			{
				return;
			}
#endif
			if ((false_topic_subset & newspaper[i]) == 0)
			{
				return;
			}
		}




#if 0		
		cout << "temp = " << temp << '\n';

		for (int i = 1; i <= F; i++)
		{
			if (false_topic_subset & (1 << i))
			{
				cout << i << ' ';
			}
		}
		cout << '\n';
#endif
		int temp = 0;

		for (int i = 1; i <= F; i++)
		{
			if (false_topic_subset & (1 << i))
			{
				++temp;
			}
		}

		//cout << "temp = " << temp << '\n';
		//최솟값 구하기
		min_ans = min(min_ans, temp);

		//최댓값 구하기
		max_ans = max(max_ans, temp);

		return;
	}


	false_topic_subset |= (1 << cur_topic);
	bool is_proceed = true;

	//거짓 토픽이 각 신문사별로 1개를 유지하는지 체크
	for (int i = 0; i < N; i++)
	{
#if 0
		if ((popcount(false_topic_subset & newspaper[i]) >= 2))
		{
			is_proceed = false;
			false_topic_subset &= ~(1 << cur_topic);
			break;
		}
#endif
		unsigned int temp_false_topic = false_topic_subset & newspaper[i];

		//temp_false_topic에 2개 이상의 토픽이 포함되어 있는지 체크
		if ((temp_false_topic & (temp_false_topic - 1)) != 0)
		{
			is_proceed = false;
			false_topic_subset &= ~(1 << cur_topic);
			break;
		}

	}

	if (is_proceed == true)
	{
		//현재 cur_topic을 추가하는 경우
		go(dep + 1, cur_topic + 1, false_topic_subset);

		false_topic_subset &= ~(1 << cur_topic);
	}

	//현재 cur_topic을 추가하지 않은 경우
	go(dep + 1, cur_topic + 1, false_topic_subset);
}

void solution()
{
	go(0, 1, 0);

	cout << min_ans << ' ' << max_ans << '\n';
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