/*
    <백트래킹 - 순열>

    1. 친구들의 관계를 맺음
        1-1. 친구들(정점)을 간선으로 연결하여 그래프 구성
    2. 친구들을 순열로 구성
       go(dep, pair_cnt)
       {
            if(dep == N)
            {
                 친구 관계 체크
            }

            u = dep번쨰 친구1
            v = dep번쨰 친구2

            if(u와 v가 아직 무대에 올라가지 않은 경우)
            {
                visit[u] = true;
                visit[v] = true;
                
                go(dep+1, pair_cnt+1);

                visit[u] = false;
                visit[v] = false;

            }

            go(dep+1, pair_cnt);

         }       

*/

#include <iostream>
#include <algorithm>
#include <vector>

#include <climits>
using namespace std;

int N, M;
vector<pair<int, int>> graph_vt;;
bool visit[21];

int ans = 0;

void input()
{
    cin >> N >> M;

    for(int i=0; i < M; i++)
    {
        int u, v;

        cin >> u >> v;

        //u와 v가 친구 관계임을 그래프에 표시
        graph_vt.push_back({u, v});
    }
}

void go(int dep, int pair_cnt)
{
    if(dep == M)
    {
        // 아직 자리가 남았다면 (전체 N보다 작다면) 로봇 댄서 1명 추가
        int total_people = pair_cnt * 2;
        
        if(total_people < N)
        {
            total_people++;
        }

        ans = max(ans, total_people);

        return;
    }

    int u = graph_vt[dep].first;
    int v = graph_vt[dep].second;

    //u와 v가 아직 무대에 올라가지 않은 경우
    if(!visit[u] && !visit[v])
    {
        visit[u] = true;
        visit[v] = true;    
        go(dep+1, pair_cnt+1);
        visit[u] = false;
        visit[v] = false;   
    }

    go(dep+1, pair_cnt);
    
}

void solution()
{
    if(M == 0)
    {
        cout << 1 << '\n';
        return;
    }

    go(0, 0);

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

