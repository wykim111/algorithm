/*
    < 재귀 >
    1. Row, Col 입력.
    2. 중간 위치를 구해야 함.
        2-1. center_y = Row / 2
        2-2. center_x = Col / 2
    
    3. 재귀 탐색
        go(cur_y, cur_x, row_len, col_len)
        {
            //base case
            if (row_len 혹은 col_len이 짝수인 경우이거나 row_len 혹은 col_len이 0인 경우)
            {
                return;
            }
            ++ans;
            ll next_row_len = row_len / 2;
            ll next_col_len = col_len / 2;

            go(cur_y - (next_row_len/2)-1, cur_x + (next_col_len/2)+1, next_row_len, next_col_len); // 우상단
            go(cur_y - (next_row_len/2)-1, cur_x - (next_col_len/2)-1, next_row_len, next_col_len); // 좌상단
            go(cur_y + (next_row_len/2)+1, cur_x - (next_col_len/2)-1, next_row_len, next_col_len); // 좌하단
            go(cur_y + (next_row_len/2)+1, cur_x + (next_col_len/2)+1, next_row_len, next_col_len); // 우하단

        }

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int ans = 0;
ll N, M;
ll start_y, start_x;

void input()
{
    cin >> N >> M;

    start_y = N / 2;
    start_x = M / 2;
}

void go(ll cur_y, ll cur_x, ll row_len, ll col_len)
{
    cout << "cur_y: " << cur_y << ", cur_x: " << cur_x << ", row_len: " << row_len << ", col_len: " << col_len << "\n";
    if(row_len % 2 == 0 || col_len % 2 == 0 || row_len == 0 || col_len == 0)
    {
        return;
    }
    
    ++ans;
    ll next_row_len = row_len / 2;
    ll next_col_len = col_len / 2;

    go(cur_y - (next_row_len/2)-1, cur_x + (next_col_len/2)+1, next_row_len, next_col_len); // 우상단
    go(cur_y - (next_row_len/2)-1, cur_x - (next_col_len/2)-1, next_row_len, next_col_len); // 좌상단
    go(cur_y + (next_row_len/2)+1, cur_x - (next_col_len/2)-1, next_row_len, next_col_len); // 좌하단
    go(cur_y + (next_row_len/2)+1, cur_x + (next_col_len/2)+1, next_row_len, next_col_len); // 우하단
}

void solution()
{
    // 예제 N = 7, M = 15 
    //start_y = 3, start_x = 7
    go(start_y, start_x, N, M);

    cout << ans << '\n';
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