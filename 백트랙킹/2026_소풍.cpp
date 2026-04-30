/*
    <백트래킹 - subset>

    1.  친구 관계 저장
        1-1. friends_arr[901][901] : 친구 관계 저장
        1-2. friends_cnt_arr[901] : 각 친구가 친구인 사람 수 저장
        1-3. 친구 수가 K명 이상인 친구들만 subset 탐색 대상으로 선정
    2. 현재 i번째 친구와 subset에 있는 친구들이 모두 친구인지 체크
        for(int friend_in_subset : friends_subset_vt)
        {
            if(friends_arr[i][friend_in_subset] == false)
            {
                //i번째 친구는 subset에 있는 친구들과 모두 친구가 아님
                return false;
            }
        }
    3. 탐색 시작
       go(int dep)
       {
            //base case
            if(friends_subset_vt.size() == K)
            {
                //subset에 있는 친구들 출력    
                exit(0);
            }
            
            //현재 dep번쨰 친구를 선택하는 경우
            if(현재 dep 번쨰 친구와 subset에 있는 친구들 모두 친구인 경우)
            {
                friends_subset_vt.push_back(dep);
                go(dep + 1);
                friends_subset_vt.pop_back();
            }

            //현재 dep번쨰 친구를 선택하지 않은 경우
            if(현재 dep 번쨰 친구를 선택하지 않은 경우에도 K명 이상 되는 경우)
            {
                go(dep + 1);    
            }
       
       
        }

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int K, N, F;
bool friends_arr[901][901];
int friends_cnt_arr[901];

vector<int> friends_subset_vt;
vector<int> friends_candidate_vt;

void input()
{
    cin >> K >> N >> F;

    for(int i=0; i < F; i++)
    {
        int friends1, friends2;

        cin >> friends1 >> friends2;

        friends_arr[friends1][friends2] = true;
        friends_arr[friends2][friends1] = true;

        friends_cnt_arr[friends1]++;
        friends_cnt_arr[friends2]++;
    }
}

bool is_all_friends(int friends_idx)
{
    for(int friend_in_subset : friends_subset_vt)
    {
        if(friends_arr[friends_idx][friend_in_subset] == false)
        {
            //friends_idx 번째 친구는 subset에 있는 친구들과 모두 친구가 아님
            return false;
        }
    }

    return true;
}

void go(int dep)
{
    //base case 1 : 필요한 친구 수 K명 만큼 subset에 있는 경우
    if(friends_subset_vt.size() == K)
    {
        for(int friend_in_subset : friends_subset_vt)
        {
            cout << friend_in_subset << "\n";
        }
        exit(0);
    }

    //base case 2 : 현재 dep번째 친구를 선택하여도 K명 이상 만족하지 못하는 경우, 더 이상 탐색할 필요 없음
    if(friends_subset_vt.size() + (N - dep) < K)
    {
        return;
    }

    //base case 3 : 친구 후보 벡터의 범위를 벗어난 경우
    if(dep == friends_candidate_vt.size())
    {
        return;
    }

    
    if(is_all_friends(friends_candidate_vt[dep]))
    {
        //현재 dep번쨰 친구를 선택하는 경우 : 여기에서는 최대한 K명을 맞춰야 함
        friends_subset_vt.push_back(friends_candidate_vt[dep]);
        go(dep + 1);
        friends_subset_vt.pop_back();
    }


    //현재 dep번쨰 친구를 선택하지 않은 경우
    go(dep + 1);
}


void solution()
{
    //친구 수가 K명 이상인 친구들만 subset 탐색 대상으로 선정하기 위해 친구 후보 벡터에 넣기
    for(int i=1; i<= N; i++)
    {
        if(friends_cnt_arr[i] >= K-1)
        {
            friends_candidate_vt.push_back(i);
        }
    }

    go(0);

    cout << -1 << '\n';

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