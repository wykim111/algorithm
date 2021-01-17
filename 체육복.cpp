#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{
	int answer = 0;
	int person[31];

	for (int i = 0; i <= 31; i++)
	{
		person[i] = 0;
	}

	for (int i = 0; i < lost.size(); i++)
	{
		person[lost[i]]--;
	}
	for (int i = 0; i < reserve.size(); i++)
	{
		person[reserve[i]]++;
	}

	//전체 탐색 진행
	for (int i = 0; i < lost.size(); i++)
	{
		//앞사람이나 뒷사람의 여분을 가져오는 경우
		//도난 당했으나 여분이 있는 경우
		if (person[lost[i]] != -1)
			continue;
		//앞사람이 있는 경우
		if (person[lost[i] - 1] == 1)
		{
			person[lost[i]] = 0;
			person[lost[i]-1] = 0;
			
		}
		else if(person[lost[i]+1] == 1)//뒷사람이 여벌이 있음
		{
			person[lost[i]] = 0;
			person[lost[i] + 1] = 0;
		}

	}
	for (int i = 1; i <= n; i++)
	{
		if (person[i] != -1)
			answer++;
	}
	
	return answer;
}
