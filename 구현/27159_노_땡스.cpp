/*
    < 구현 >

    1. 정수들을 오름차순으로 정렬한 뒤, 이웃한 수끼리의 차가 1인 구간들로 그룹을 나눕니다.
    2. 각 그룹별로 가장 작은 수를 모두 합한 값이 점수가 됩니다.

   예를 들어 가지고 있는 수 카드가 6, 7, 10, 12, 13, 14, 15, 20, 21, 22라면, [6, 7], [10], [12, 13, 14, 15], [20, 21, 22]의 4개의 그룹으로 나뉘며, 점수는 6 + 10 + 12 + 20 = 48점입니다.
   가지고 있는 수 카드가 주어졌을 때 점수를 계산하는 프로그램을 작성하세요.
=========================================================================================================================

    1. vector를 이용하여 인덱스를 기준으로 구간 별로 저장
    2. vector의 각 0번째 인덱스 합산

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> section_vt;
vector<int> num_vt;
int N;



void input()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int num;

        cin >> num;

        num_vt.push_back(num);
    }
}

void solution()
{
    sort(num_vt.begin(),num_vt.end());

    for(int i=0;i<num_vt.size();i++)
    {
       if(i == 0 || num_vt[i] != (num_vt[i-1] + 1))
       {
            section_vt.emplace_back();
       }

       section_vt.back().push_back(num_vt[i]);
    }

    int sum = 0;
    for (const auto& sec : section_vt)
        sum += sec.front();   // 정렬돼 있으니 첫 원소가 그 그룹의 최솟값

    cout << sum << '\n';


}

int main()
{
    input();
    solution();

    return 0;
}
