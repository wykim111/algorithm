#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#if 0 //재귀 버전
int N, M;
int input_table[1025][1025];
int start_y, start_x;
int end_y, end_x;
int ans;

void input()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> input_table[i][j];
        }
    }
   
    
}

void go(int dep, int sum)
{
    if(dep == (end_y+1))
    {
        ans = sum;

        return;
    }

    for(int i = start_x; i <= end_x; i++)
    {
       sum += input_table[dep][i];
    }

     go(dep + 1, sum);
}

void solution()
{
     for(int i = 0; i < M; i++)
     {   
        cin >> start_y >> start_x >> end_y >> end_x;
        ans = 0;
        go(start_y, 0);

        cout <<"ans :" << ans << "\n";
     }
}
#else //DP 버전
int N, M;
int input_table[1025][1025];
int start_y, start_x;
int end_y, end_x;
int ans;
int dp[1025][1025];


void input()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> input_table[i][j];
        }
    }
}

void solution()
{
    for(int i=1; i <= N; i++)
    {
        for(int j=1; j <= N; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + input_table[i][j];
        }
    }

    for(int i = 0; i < M; i++)
    {   
        cin >> start_y >> start_x >> end_y >> end_x;

        ans = dp[end_y][end_x] - dp[start_y-1][end_x] - dp[end_y][start_x-1] + dp[start_y-1][start_x-1];

        cout << ans << "\n";
     }
}

#endif


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solution();


    return 0;
}
