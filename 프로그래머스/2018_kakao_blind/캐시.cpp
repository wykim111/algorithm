/*
	LRU 알고리즘
	: 가장 오래 캐시에 있는 원소를 제외


	

*/
/*
	LRU 알고리즘
	: 캐시에 가장 오래 있는 원소를 먼저 제거

	- 모든 도시와 캐시와 비교하여 도시가 존재하는 경우
	해당 도시를 캐시에 없애고 뒤에 추가
	- 모든 도시와 캐시와 비교하여 도시가 존재하지 않은 경우,
	캐시사이즈가 정해진 사이즈에 꽉 찼으면 맨 앞에 제거하고 추가
	캐시사이즈가 정해진 사이즈에 여유가 있으면 원소 추가

*/
#include<iostream>
#include <string>
#include <vector>

using namespace std;

void lowerAlphabet(string& s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] += 32;
		}
	}
}

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	int i, j;
	vector<string> cache;

	if (cacheSize == 0)
	{
		return cities.size() * 5;
	}

	for ( i=0;i<cities.size(); i++)
	{
		//문자열 데이터를 모두 소문자로 변환
		lowerAlphabet(cities[i]);
		for ( j = 0; j < cache.size(); j++)
		{
			if (cache[j] == cities[i])
			{
				//hit +1
				answer += 1;
				//존재하는 원소 지우고 추가
				cache.erase(cache.begin()+j);
				//cache[j]가 아닌 cities[i]로 해야함
				//왜냐하면 위에서 해당 원소를 지웠기 때문에 인덱스가 수정됨
				cache.push_back(cities[i]);


				break;
			}
		}
		//캐시에 원소를 다 탐색해도 없는 경우
		if (j == cache.size())
		{
			answer += 5;
			//캐시 사이즈가 정해진 캐시 사이즈보다 이상인 경우
			if (cache.size() >= cacheSize)
			{
				//맨 앞 원소를 비우고 뒤에 추가
				cache.erase(cache.begin());
				cache.push_back(cities[i]);
			}
			else
			
			{
				cache.push_back(cities[i]);
			}


		}
	}



	return answer;
}

int main()
{
	vector<string>cities;

	for (int i = 0; i < 12; i++)
	{
		string str;
		
		cin >> str;
		cities.push_back(str);
	}

	cout << solution(5, cities) << endl;

	return 0;
}
