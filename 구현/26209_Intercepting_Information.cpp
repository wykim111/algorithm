/*
    <구현>

    1. 8개의 숫자를 차례대로 입력받습니다.
    2. 입력받은 숫자 중에 9가 하나라도 있는지 확인합니다.
    3. 9가 발견되면 즉시 F를 출력하고 프로그램을 종료합니다.
    4. 8개의 숫자를 다 검사했는데도 9가 없다면 S를 출력합니다.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> data_vt;
    
void input()
{
    for(int i=0; i < 8; i++)
    {
        int num;
        cin >> num;
        data_vt.push_back(num);

    }
}

void solution()
{
    bool is_nine = false;

    for(int i=0; i < data_vt.size();i++)
    {
        if(data_vt[i] == 9)
        {
            is_nine = true;
            break;
        }
    }

    if(is_nine == true)
    {
        cout << "F" << "\n";
    }
    else
    {
        cout << "S" << "\n";
    }
}

int main()
{
    input();
    solution();

    return 0;
}