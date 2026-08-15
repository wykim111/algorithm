/*
    < 구현 >
    
    1. hash map을 이용하여 해당하는 과일을 키로 지정하여 갯수 카운트
    2. 특정 과일의 갯수 총합이 5이면 "Yes" 출력.
    3. 특정 과일의 갯수 총합이 5가 아니면 "No" 출력.

*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

unordered_map<string, int> halliGalli_mp;

int N;

void input()
{
    cin >> N;

    for(int i = 0 ;i < N; i++)
    {
        string fruits;
        int fruits_cnt;

        cin >> fruits >> fruits_cnt;

        halliGalli_mp[fruits] += fruits_cnt;
    }
}

void solution()
{
    for(unordered_map<string, int>::iterator iter = halliGalli_mp.begin(); iter != halliGalli_mp.end(); iter++)
    {
        if(iter->second == 5)
        {
            cout << "YES" << '\n';

            return;
        }
    }


    cout << "NO" << '\n';

}


int main()
{
    input();
    solution();

    return 0;
}

