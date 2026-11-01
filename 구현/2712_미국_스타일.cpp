/*
    < 구현 >

    [단위 변환 계수 요약]

    - kg -> lb : 값 * 2.2046
    - lb -> kg : 값 * 0.4536
    - l  -> g  : 값 * 0.2642
    - g  -> l  : 값 * 3.7854

*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int T;
double input_num;
string input_unit;

double fNum = 0;
string unit = "";

void init()
{
    fNum = 0;
    unit = "";
}

void input()
{
    cin >> input_num >> input_unit; 
    cin.ignore(); // 개행 제거
}

void solution()
{
    if(input_unit == "kg")
    {
        fNum = (input_num * 2.2046);
        unit = "lb";
    }
    else if(input_unit == "lb")
    {
        fNum = (input_num * 0.4536);
        unit = "kg";
    }
    else if(input_unit == "l")
    {
        fNum = (input_num * 0.2642);
        unit = "g";
    }
    else if(input_unit == "g")
    {
        fNum = (input_num * 3.7854);
        unit = "l";
    }



    cout.precision(4);
    cout << fixed;

    cout << fNum <<" "<< unit << '\n'; // 2.2046 lb
}

int main()
{
    cin >> T;

    while(T--)
    {
        init();
        input();
        solution();
    }

    return 0;
}