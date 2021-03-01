/*
	
	- food time을 오름차순으로 정렬
	- 소요시간이 짧은 음식부터 검사
	-> time = (현재 음식 시간 - 이전에 검사한 음식의 시간)* ( 남은 음식의 수)
	- k보다 작은 경우 남은 시간 감소 시키고 이전에 검사한 음식의 시간을 현재 음식 시간으로 업데이트
	- k보다 큰 경우 다시 정렬 하고, 현재 음식 + (k%남은 음식의 수)로 다음 음식 출력 

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}


int solution(vector<int> food_times, long long k) {
	int answer = 0;
	vector<pair<int, int>> foods;//음식의 시간, 음식 id 저장
	int size = food_times.size();

	for (int i = 0; i < size; i++)
	{
		foods.push_back(make_pair(food_times[i],i+1));
	}
	//오름차순 정렬
	sort(foods.begin(), foods.end());

	int preTime = 0;

	for (vector<pair<int, int>>::iterator iter = foods.begin(); iter != foods.end(); iter++,size--)
	{
		long long useTime = (long long)(iter->first - preTime) * size;

		//이전에 먹은 요리의 시간을 뺄 때 0인 경우(시간이 같음)
		if (useTime == 0)
			continue;
		if (useTime <= k)
		{
			k -= useTime; //음식을 먹은 시간만큼 감소
			preTime = iter->first;//이전 시간 변수를 현재 시간으로 업데이트
		}
		else
		{
			k = k % size;
			sort(iter, foods.end(), comp);
			return (iter + k)->second;
		}
	}


	return -1;
}
