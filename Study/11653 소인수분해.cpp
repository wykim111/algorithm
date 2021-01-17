/*
	1.2부터 N까지 처음에 나누어 떨어지는 수를 찾는다.
	2.나누어 떨어진다면 해당 몫을 1번과 같이 반복한다.
	3. 몫이 1이 되면 종료
*/

#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;
int N;

vector<int> vt;

int main()
{
	int divisor, divisored;//제수 피제수

	scanf("%d", &N);
	
	divisored = N; 

	while (divisored != 1)
	{
		for (divisor = 2; divisor <= divisored; divisor++)
		{
			if (divisored % divisor == 0)
			{
				divisored /= divisor;
				vt.push_back(divisor);
				divisor = 1;
			}
		}
	}

	for (int i = 0; i < vt.size(); i++)
	{
		printf("%d\n", vt[i]);
	}

	return 0;
}