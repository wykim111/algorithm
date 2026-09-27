/*
    <구현>

    1. 문자열의 길이를 구함.
    2. 마지막 자리의 문자를 숫자로 치환하여 m으로 저장
    3. 미지수 탐색
        for(x = 0 ~ 9)
        {
            for(i=0 ~ str_len)
            {
                //배수 결정
                if((i % 2) == 0)
                {
                    multiple = 1;
                }
                else
                {
                    multiple = 3;
                }

                //숫자인 경우, 연산
                if(str[i] >= '0' && str[i] <= '9')
                {
                    sum += (str[i] - '0') * multiple;
                }
                else
                {
                    sum += x * multiple;
                }

            }

            remainder = sum % 10;

            if(remainder == 0)
            {
                temp_m = 0;
            }
            else
            {
                temp_m = 10 - remainder;
            }

            if(temp_m == m)
            {
                ans = x;
                break;
            }


        }

*/

#include <iostream>
#include <algorithm>
#include <string>  

using namespace std;

string isbn_str;

void input()
{
    cin >> isbn_str;
}

void solution()
{
    int str_len = isbn_str.length();
    int m = isbn_str[str_len-1] - '0';
    int sum = 0;
    int multiple = 0;
    int remainder = 0;
    int temp_m = 0;
    int ans = 0;

    for(int x = 0; x <= 9; x++)
    {
        sum = 0;

        for(int i = 0; i < str_len-1; i++)
        {
            if((i % 2) == 0)
            {
                multiple = 1;
            }
            else
            {
                multiple = 3;
            }

            if(isbn_str[i] >= '0' && isbn_str[i] <= '9')
            {
                sum += (isbn_str[i] - '0') * multiple;
            }
            else
            {
                sum += x * multiple;
            }

        }

        remainder = sum % 10;

        if(remainder == 0)
        {
            temp_m = 0;
        }
        else
        {
            temp_m = 10 - remainder;
        }

        if(temp_m == m)
        {
            ans = x;
            break;
        }
    }

    cout << ans << '\n';
}

int main()
{
    input();
    solution();


    return 0;
}