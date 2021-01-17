#include <string>
#include <vector>
#include<iostream>
#include <math.h>
using namespace std;

long long solution(long long n) {
	long long answer = 0;
	long long temp = n;
	int Max_Num = 0;
	int idx = 0;
	int arr[10];

	//자릿수 찾아내기
	while (temp != 0)
	{
		temp /= 10;
		idx++;
	}
	//cout << idx << endl;
	//큰 수를 기준으로 내림차순
	temp = n;
	for (int i = 0; i < idx; i++)
	{
		arr[idx-i-1] = temp % 10;
		temp /= 10;

	}

	for (int i = 0; i < idx - 1; i++)
	{
		for (int j = 0; j < idx - i - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int t;
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
	int temp_idx = idx-1;
	for (int i = 0; i < idx; i++)
	{
		answer += arr[i] * pow(10, temp_idx);
		temp_idx--;
	}

	cout << answer;

	return answer;
}

int main()
{
	long long n;

	cin >> n;

	solution(n);
}
