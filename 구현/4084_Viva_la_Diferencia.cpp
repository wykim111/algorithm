#include <iostream>
#include <algorithm>

#include <cmath>

using namespace std;

int arr[4];

void input()
{
    for(int i = 0; i < 4; i++)
    {
        cin >> arr[i];
    }
}

void solution()
{
    int cnt = 0;

    while(true)
    {
        int diff_a = abs(arr[0] - arr[1]);
        int diff_b = abs(arr[1] - arr[2]);
        int diff_c = abs(arr[2] - arr[3]);
        int diff_d = abs(arr[3] - arr[0]);

        if(diff_a == 0 && diff_b == 0 && diff_c == 0 && diff_d == 0)
        {
            cout << cnt << "\n";
            break;
        }


        if(diff_a == diff_b && diff_b == diff_c && diff_c == diff_d && diff_d == diff_a)
        {
            ++cnt;
            cout << cnt << "\n";
            break;
        }

        arr[0] = diff_a;
        arr[1] = diff_b;
        arr[2] = diff_c;
        arr[3] = diff_d;

        ++cnt;
    }
}

int main()
{
    while(true)
    {
        input();

        if(arr[0] == 0 && arr[1] == 0 && arr[2] == 0 && arr[3] == 0)
        {
            break;
        }

        solution();
    }

    return 0;
}
