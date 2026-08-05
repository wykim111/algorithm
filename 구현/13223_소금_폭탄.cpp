/*
    < 구현 >

    1. hh:mm:ss 형식의 시간을 초 단위로 변환.
    2. 차이를 계산하여, hh:mm:ss 형식으로 변환. 


*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string input_current_time;  // 현재 시간
string input_salt_time;     // 소금을 투하하는 시간

void input()
{
    cin >> input_current_time;
    cin >> input_salt_time;
}

int conv_time_to_sec(const string& time_str)
{
    int hours = stoi(time_str.substr(0, 2));
    int minutes = stoi(time_str.substr(3, 2));
    int seconds = stoi(time_str.substr(6, 2));

    return hours * 3600 + minutes * 60 + seconds;
}

void solution()
{
    int current_time_sec = 0;
    int salt_time_sec = 0;

    // 현재 시간을 초 단위로 변환
    current_time_sec = conv_time_to_sec(input_current_time);
    
    // 소금을 투하하는 시간을 초 단위로 변환
    salt_time_sec = conv_time_to_sec(input_salt_time);

    // 시간 차이 계산
    int time_diff_sec = salt_time_sec - current_time_sec;

    if(time_diff_sec < 0)
    {
        // 소금을 투하하는 시간이 현재 시간보다 이전인 경우, 하루를 더해줌
        time_diff_sec += 24 * 3600;
    }

    // 시간 차이를 hh:mm:ss 형식으로 변환
    int hours = time_diff_sec / 3600;
    int minutes = (time_diff_sec % 3600) / 60;
    int seconds = time_diff_sec % 60;

    // 결과 출력 (hh:mm:ss 형식)
    if(hours < 10) cout << "0";
    cout << hours << ":";
    if(minutes < 10) cout << "0";
    cout << minutes << ":";
    if(seconds < 10) cout << "0";
    cout << seconds << endl;
}

int main()
{
    input();
    solution();

    return 0;
}
