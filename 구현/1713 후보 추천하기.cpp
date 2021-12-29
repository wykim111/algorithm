/*
	==========================================================================================
	1. 큐의 사이즈가 비어있지 않은 경우 (꽉 찬 경우)
	  - 현재까지 추천 받은 횟수가 가장 적은 학생의 사진을 삭제
	  - 현재까지 추천 받은 횟수가 가장 적은 학생이 2명 이상일 경우 가장 오래된 학생 삭제
	2. 현재 큐에 있는 학생들이 추천 받은 경우 추천 받은 횟수만 증가
	3. 큐에 삭제된 학생의 경우 0으로 초기화

	============================================================================================

*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;


typedef struct _person
{
	int student_no;//학생 번호
	int recommend_cnt;//추천 수
	int timeworn;//순차적으로 저장 (같은 추천수인 경우 가장 오래된거 찾기 위함)
}Person;

#if 1

bool comp(Person p1, Person p2)//vector sort
{
	if (p1.recommend_cnt == p2.recommend_cnt)
	{
		return p1.timeworn > p2.timeworn;//시간이 오래될수록 숫자가 작음 (== 내림차순)
	}
	return p1.recommend_cnt > p2.recommend_cnt;//내림차순	
}
bool comp_asc_stu_no(Person p1, Person p2)//vector sort
{

	return p1.student_no < p2.student_no;//오름차순	
}
#else
struct comp
{
	//min heap
	bool operator()(int n1, int n2)
	{

		return n1 > n2;//추천수가 작은것부터 뽑음
	}
};

#endif

#if 1
vector<Person> vt;
#else
priority_queue<int, vector<int>, comp>pq;
#endif
int photo_size = 0;
int recommend_size = 0;
int time_priority = 0;

int main()
{
	cin >> photo_size;
	cin >> recommend_size;

	for (int i = 0; i < recommend_size; i++)
	{
		Person  input;
		bool same_flag = false;

		cin >> input.student_no;

		//큐에 존재하는 경우 카운트만 증가
		for (int iter = 0; iter < vt.size(); iter++)
		{
			if (vt[iter].student_no == input.student_no)
			{
				same_flag = true;
				vt[iter].recommend_cnt++;
			}
		}

		//큐에 존재하지 않은 경우
		if (same_flag == false)
		{
			//큐 사이즈가 충분한지
			if ((vt.size() < photo_size))
			{
				input.recommend_cnt = 1;
				input.timeworn = (time_priority);
				time_priority++;

				vt.push_back(input);

			}
			else//큐 사이즈가 꽉 찼는지
			{
				//추천받은 횟수가 적은게 다수인 경우 가장 오래된 학생 삭제
				sort(vt.begin(), vt.end(), comp);
				vt.pop_back();

				input.recommend_cnt = 1;
				input.timeworn = (time_priority);
				time_priority++;

				vt.push_back(input);
			}
		}


	}
	sort(vt.begin(), vt.end(), comp_asc_stu_no);


	for (int i = 0; i < vt.size(); i++)
	{
		if (i == vt.size() - 1)
		{
			cout << vt[i].student_no;
		}
		else
		{
			cout << vt[i].student_no << ' ';
		}
	}
	cout << '\n';


	return 0;
}
