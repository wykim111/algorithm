/*
	< 백트래킹 - subset>

	1. 탐색
		go(dep, int utility_sum, int work_sum)
		{
			if(dep == 모든 과목 수)
			{
				//최대 효용 업데이트

				return;
			}

			// dep번째 과목을 선택하는 경우
			if(현재 과목을 선택하는 조건에 만족하는 경우)
			{
				cur_utility = 현재 과목의 효용
				cur_work = 현재 과목의 작업량

				//현재 선택한 과목에 대해 시간 체크
				go(dep+1, utility_sum + cur_utility, work_sum + cur_work);
				//현재 선택한 과목에 대해 시간 체크 해제
			}

			// dep번째 과목을 선택하지 않은 경우
			go(dep+1, utility_sum, work_sum);
		}
	2. 현재 과목을 선택하는 조건에 만족하지 않은 경우 제외해야 함.
		2-1. 내 시간대와 겹치는 과목은 제외
		2-2. 내 작업량을 초과하는 과목은 제외

*/

#include <iostream>
#include <algorithm>
#include <vector>

#include <cstring>
#include <climits>
using namespace std;

int n, m, C; // 고려 중인 과목의 수, 일주일 동안의 수업 시간 대 개수, 당신이 감담할 수 있는 최대 작업 허용량
int K; // test case

typedef struct _subject
{
	int u; //효용
	int v; // 작업량
	int m; // 수업 횟수
	vector<int> subject_time_vt;
}subject;

subject subject_arr[21];
bool subject_time_line[101];
int max_utility;
vector<int> subject_subset_vt;

void init()
{
	//memset(subject_time_line, false, sizeof(subject_time_line));
	fill(begin(subject_time_line), end(subject_time_line), false);

	max_utility = 0;

	for (int i = 0; i < 21; i++) 
	{
		subject_arr[i].subject_time_vt.clear();
	}

	subject_subset_vt.clear();
}

void input()
{
	cin >> n >> m >> C;

	for (int i = 0; i < n; i++)
	{
		int u, v, m;

		cin >> u >> v >> m;

		subject_arr[i].u = u;
		subject_arr[i].v = v;
		subject_arr[i].m = m;

		for (int j = 0; j < m; j++)
		{
			int time_line;

			cin >> time_line;

			subject_arr[i].subject_time_vt.push_back(time_line);

		}
	}
}

bool is_ok(int dep, int in_utility_sum, int in_work_sum)
{
	// 1. 작업량 초과 검사
	if ((in_work_sum + subject_arr[dep].v) > C)
	{
		return false;
	}

	// 2. 시간대 겹침 검사
	for (int i = 0; i < subject_arr[dep].subject_time_vt.size(); i++)
	{
		int target_time = subject_arr[dep].subject_time_vt[i];

		// 이미 누군가 차지한 시간대라면 즉시 false
		if (subject_time_line[target_time] == true)
		{
			return false;
		}
	}

	return true;
}


void go(int dep, int utility_sum, int work_sum)
{
	if (dep == n)
	{
		max_utility = max(max_utility, utility_sum);

		return;
	}

	// dep번째 과목을 선택하는 경우
	if (is_ok(dep, utility_sum, work_sum) == true)
	{
		subject_subset_vt.push_back(dep);
		
		for (int i = 0; i < subject_arr[dep].subject_time_vt.size(); i++)
		{
			int temp_time_line = subject_arr[dep].subject_time_vt[i];

			subject_time_line[temp_time_line] = true;
		}


		go(dep + 1, utility_sum + subject_arr[dep].u, work_sum + subject_arr[dep].v);

		for (int i = 0; i < subject_arr[dep].subject_time_vt.size(); i++)
		{
			int temp_time_line = subject_arr[dep].subject_time_vt[i];

			subject_time_line[temp_time_line] = false;
		}


		subject_subset_vt.pop_back();
	}
	// dep번째 과목을 선택하지 않은 경우
	go(dep + 1, utility_sum, work_sum);
}

void solution(int tc)
{
	go(0, 0, 0);

	cout << "Data Set " << tc << ":\n";
	cout << max_utility << "\n";
}

int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K;

	for (int i = 1; i <= K; i++)
	{
		init();
		input();
		solution(i);
	}
	
	

	return 0;
}

