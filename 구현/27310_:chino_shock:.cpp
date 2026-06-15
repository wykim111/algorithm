#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string input_str;

void input()
{
    cin >> input_str;
}

void solution()
{
    int str_size = input_str.size();
    int under_bar_cnt = 0;
    int colon_cnt = 0;
    int result = 0;

    for(int i=0; i< str_size; i++)
    {
        if(input_str[i] == '_')
        {
            ++under_bar_cnt;
        }
        else if(input_str[i] == ':')
        {
            ++colon_cnt;
        }
    }

    result = str_size + colon_cnt + (under_bar_cnt * 5);

    cout << result << '\n';


}

int main()
{
    input();
    solution();

    return 0;
}
