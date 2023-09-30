/*
		<투 포인터 알고리즘>


+ 원래 회전 초밥은 손님이 마음대로 초밥을 고르고, 먹은 초밥만큼 식대를 계산하지만, 벨트의 임의의 한 위치부터 k개의 접시를 연속해서 먹을 경우 할인된 정액 가격으로 제공한다.
+ 각 고객에게 초밥의 종류 하나가 쓰인 쿠폰을 발행하고, 1번 행사에 참가할 경우 이 쿠폰에 적혀진 종류의 초밥 하나를 추가로 무료로 제공한다.
  만약 이 번호에 적혀진 초밥이 현재 벨트 위에 없을 경우, 요리사가 새로 만들어 손님에게 제공한다.
+ 손님이 먹을 수 있는 초밥 가짓수의 최댓값을 구하는 프로그램을 작성하시오.



1. left지점을 출발점으로 연속해서 k개를 먹는다.
2. 마지막 K번쨰 먹은 위치까지 right 지점으로 탐색한다.
3. left와 right 사이에 먹은 초밥의 가짓수를 카운트
4. 최댓값 업데이트


*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N;//회전벨트에 놓인 접시의 수
int d;//초밥의 가짓수
int k;//연속해서 먹는 접시의 수
int c;//쿠폰의 수

int sushi_arr[30001];
bool visit[30001];//초밥에 대한 중복 여부 체크
int coupon = 0;


int Modular = 0;
int answer = 0;

void input()
{
	cin >> N >> d >> k >> c;

	Modular = N;

	for (int i = 0; i < N; i++)
	{
		cin >> sushi_arr[i];
	}
}

void solution()
{


	//투포인터 알고리즘
	for (int left = 0; left < N; left++)
	{
		int  duplicate_cnt = 0;//중복된 수 카운트
		int coupon = 1;//쿠폰 초밥이 있는지 체크

		memset(visit, false, sizeof(visit));

		for (int right = 0; right < k; right++)
		{
			int idx = ((left + right) % Modular);

			if (visit[sushi_arr[idx]] == true)
			{
				++duplicate_cnt;
			}
			else
			{
				visit[sushi_arr[idx]] = true;
			}

			if (sushi_arr[idx] == c)//쿠폰이 존재하는 경우
			{
				coupon = 0;
			}

		}
#if 0
		for (int i = 0; i < sushi_vt.size(); i++)
		{
			cout << sushi_vt[i] << ' ';
		}
		cout << '\n';
#endif

		//초밥 먹은 종류 업데이트(같은 초밥이 중복된 경우 한 가지로 정의)
		answer = max(answer, k - duplicate_cnt + coupon);

	}

	cout << answer << '\n';
}


int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}
