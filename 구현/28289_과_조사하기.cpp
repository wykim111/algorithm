/*
	< 구현 >

	1. 1학년 카운트
	2. 2학년 이상인 경우, 반 카운트
		2-1. 반이 1반 혹은 2반인 경우, 소프트웨어학과 카운트
		2-2. 반이 3반인 경우, 임베디드소프트웨어 카운트
		2-3. 반이 4반인 경우, 인공지능학과 카운트
	3. 첫째 줄에 동아리에 소속된 소프트웨어개발과 학생의 수를 출력한다.
	   둘째 줄에 동아리에 소속된 임베디드소프트웨어개발과 학생의 수를 출력한다.
	   셋째 줄에 동아리에 소속된 인공지능소프트웨어개발과 학생의 수를 출력한다.
	   넷째 줄에 동아리에 소속된 아무런 과에도 속하지 않는 1학년 학생의 수를 출력한다.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int P;
int G, C, N;
int software = 0, embedded = 0, ai = 0;
int firstYear = 0;
void input()
{
	cin >> G >> C >> N;
}

void solution()
{
	if (G == 1) {
		++firstYear;
	}
	else {
		if (C == 1 || C == 2) {
			++software;
		}
		else if (C == 3) {
			++embedded;
		}
		else if (C == 4) {
			++ai;
		}
	}
}

void output()
{
	cout << software << "\n";
	cout << embedded << "\n";
	cout << ai << "\n";
	cout << firstYear << "\n";
}

int main()
{
	cin >> P;


	for (int i = 0; i < P; i++)
	{
		input();
		solution();
	}

	output();

	return 0;
}