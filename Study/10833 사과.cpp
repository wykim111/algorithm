/*
	학생수 * (1부터 100)까지 곱한 뒤 해당 수가 사과 개수보다 많으면 그 이전 수가 최대로 나누어 준 나머지를 의미
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;
vector<pair<int, int>> vt;
int remain[100];

int cntApple(int cnt)
{
	int multiple = 1;
	int numOfApple = 0;
	int flag = 0;

	//분모(학생)가 분자(사과)보다 큰 경우 사과의 개수 그대로 반환
	if (vt[cnt].first > vt[cnt].second)
		return vt[cnt].second;

	while (true)
	{
		int temp = vt[cnt].first * multiple;
		
		//사과가 학생보다 많은 경우
		//분모(학생)가 분자(사과)보다 큰 경우 학생수에서 사과 개수를 뺀 뒤 설정하여 탈출
		if (temp > vt[cnt].second)
		{
			break;
		}
		numOfApple = vt[cnt].second % temp;

		multiple++;
	}
	return numOfApple;
}
int main()
{
	int N;
	int sum = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int student, apple;

		scanf("%d %d", &student, &apple);

		vt.push_back(make_pair( student,apple ));
	}
	/*
	for (vector<pair<int, int>>::iterator it = vt.begin(); it != vt.end(); it++)
		printf("%d %d\n", it->first, it->second);
	*/
	for (int i = 0; i < vt.size(); i++)
	{
		sum += cntApple(i);
		//printf("cntApple = %d\n", cntApple(i));
	}
	printf("%d\n", sum);

	return 0;
}