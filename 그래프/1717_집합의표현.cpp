/*
    < 그래프 - Union Find >

    1. 각 정점의 부모를 저장하는 배열 생성
        1-1. 부모를 자기 자신으로 초기화
        1-2. rank 배열을 생성하여, 각 정점의 트리 높이를 저장한다.
    2. Union-Find 알고리즘 수행
        2-1. 두 정점의 부모를 찾는다.
        2-2. 부모가 다르면, 한쪽 부모를 다른 쪽 부모로 설정한다.

        Union(a, b) {
            a = Find(a);
            b = Find(b);
            
            if(a == b) return;

            if(rank_arr[a] < rank_arr[b]) 
                parent_arr[a] = b;
            else if(rank_arr[a] > rank_arr[b])
                parent_arr[b] = a;
            else 
            {
                parent_arr[b] = a;
                rank_arr[a]++;
            }
        }

        Find(a) {
            if (parent_arr[a] == a) return a;
            return parent_arr[a] = Find(parent_arr[a]);
        }
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int parent_arr[1000001]; // 1,000,000
int rank_arr[1000001]; // 1,000,000

int n, m;
int cmd, a, b;

void input()
{
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        parent_arr[i] = i;
        rank_arr[i] = 0;
    }
}

int Find(int param_a)
{
    if (parent_arr[param_a] == param_a) 
        return param_a;
    
    return parent_arr[param_a] = Find(parent_arr[param_a]);
}

void Union(int param_a, int param_b)
{
    int x = Find(param_a);
    int y = Find(param_b);

    if (x == y) 
        return;

    if (rank_arr[x] < rank_arr[y])
        parent_arr[x] = y;
    else if (rank_arr[x] > rank_arr[y])
        parent_arr[y] = x;
    else
    {
        parent_arr[y] = x;
        rank_arr[x]++;
    }
}

void solution()
{
    cin >> cmd >> a >> b;

    if(cmd == 0)
    {
        Union(a, b);
    }
    else if( cmd == 1)
    {
        int x = Find(a);
        int y = Find(b);

        if(x == y)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    for (int i = 0; i < m; i++)
    {
        solution();
    }

    return 0;
}
