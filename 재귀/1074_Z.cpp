/*
    < 재귀 - 분할정복 >
    
    1. 재귀 탐색 (4분할)
    go(len, start_y, start_x)
    {
        // base case
        if(len == 1)
        {
            cout << cnt << '\n';
            
            return;
        }
        
        2) 재귀 호출
        len /= 2; // 길이를 절반으로 (이제 len은 한 사분면의 한 변 길이)
        int area = len * len; // 스킵할 사분면 하나의 칸 개수 (넓이)

        if (목표가 1사분면에 있다면) 
        {
            go(len, start_y, start_x);
        }
        else if (목표가 2사분면에 있다면) 
        {
            cnt += area; // 1사분면 통째로 스킵
            go(len, start_y, start_x + len);
        }
        else if (목표가 3사분면에 있다면) 
        {
            cnt += (area * 2); // 1, 2사분면 통째로 스킵
            go(len, start_y + len, start_x);
        }
        else // 목표가 4사분면에 있다면
        {
            cnt += (area * 3); // 1, 2, 3사분면 통째로 스킵
            go(len, start_y + len, start_x + len);
        }
    }  
     
*/

#include <iostream>
#include <algorithm>
#include <vector>

typedef  long long int ll;
using namespace std;


int N, r, c;
ll cnt = 0;

void input()
{
    cin >> N >> r >> c;
}

void go(int len, int start_y, int start_x)
{
    // base case
    if(len == 1)
    {
        cout << cnt << '\n';
        
        return;
    }
    
    // 재귀 호출
    len /= 2; // 길이를 절반으로 (이제 len은 한 사분면의 한 변 길이)
    int area = len * len; // 스킵할 사분면 하나의 칸 개수 (넓이)

    if (r < start_y + len && c < start_x + len) 
    {
        go(len, start_y, start_x);
    }
    else if (r < start_y + len && c >= start_x + len) 
    {
        cnt += area; // 1사분면 통째로 스킵
        go(len, start_y, start_x + len);
    }
    else if (r >= start_y + len && c < start_x + len) 
    {
        cnt += (area * 2); // 1, 2사분면 통째로 스킵
        go(len, start_y + len, start_x);
    }
    else // 목표가 4사분면에 있다면
    {
        cnt += (area * 3); // 1, 2, 3사분면 통째로 스킵
        go(len, start_y + len, start_x + len);
    }
}

void solution()
{

    go(1 << N,0, 0);
    //out << cnt << '\n';
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
