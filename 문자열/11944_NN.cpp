/*
	- 몫(M/N의 문자열 길이)만큼 문자열 출력
	- 하나의 문자열에서 나머지만큼 문자들 출력
*/
#include<iostream>
#include<string>

using namespace std;

string N_str;
int N,M;
int digitLen = 0;

int main()
{
	int Mok,Remain;
	cin >> N >> M;
	N_str = to_string(N);
	digitLen = N_str.length();


	//N이 N번 출력(N이 N개 들어갈 공간을 만듬 예를 들어 20은 40개의 공간이 있어야 20이 20개 들어감)
	for (int i = 0; i < M && i < N*digitLen; i++)
	{
		cout << N_str[i%digitLen];
	}
	
	return 0;
}
