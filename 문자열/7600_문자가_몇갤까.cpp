/*
    < 문자열>

    1. "#"을 입력받을 떄까지 입력을 받음
    2. 입력 받은 문자열에서 알파벳(대소문자 구분 x)의 갯수 출력
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

#include <cstring>

using namespace std;

bool break_flag = false;
string input_str;

void input()
{
    getline(cin, input_str);


    if(input_str == "#")
    {
        break_flag = true;
    }




}

void solution()
{
    int str_len = input_str.size();
    int cnt = 0;
    bool alphabet_flag[26];

    memset(alphabet_flag, false, sizeof(alphabet_flag));

    //알파벳을 모두 소문자로 변환
    for(int i=0;i<str_len;i++)
    {
        if(input_str[i] >= 'A' && input_str[i] <= 'Z')
        {
            input_str[i] = (input_str[i] + 32);
        }
    }

    for(int i = 0; i < str_len; i++)
    {
        // 1. 먼저 알파벳인지 확인
        if(input_str[i] >= 'a' && input_str[i] <= 'z')
        {
            int alphabet_idx = input_str[i] - 'a';

            // 2. 처음 등장한 알파벳인 경우만 카운트
            if(!alphabet_flag[alphabet_idx])
            {
                alphabet_flag[alphabet_idx] = true;
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
}


int main()
{

    while(true)
    {
        input();

        if(break_flag)
        {
            break;
        }

        solution();
    }
}