/*
    < 백트래킹 - 조합>

    1. 각 후보지마다 유효 거리에 있는 아파트의 좌표 인원을 포함.
    2. 후보지로 조합된 집합에 해당 하는 아파트의 인원 카운트.
        2-1. 조합된 집합의 후보지마다 유효 거리에 있는 아파트의 좌표 인원을 포함.
        2-2. 조합된 집합의 후보지마다 유효 거리에 있는 아파트의 좌표 인원을 포함한 결과 중 최댓값 저장.
        2-3. 각 레스토랑 후보지마다 유효 거리에 있는 아파트의 좌표 인원을 포함한  인원 중 겹치는 아파트 인원은 한번만 카운트.

*/

#include <iostream>
#include <algorithm>
#include <vector>

#include <climits>
using namespace std;

int K, R; // 레스토랑 선택 가능한 갯수, 유효 거리
int M, N; // 레스토랑의 갯수, 아파트의 갯수
bool visit[2001][2001];

int ans = INT_MIN;

typedef struct _apartment
{
    int y;
    int x;
    int cnt;
} apartment;


typedef struct _restuarant
{
    int y;
    int x;
    vector<apartment> apartment_vt;
} restaurant;

vector<restaurant> restaurant_vt;
vector<apartment> apartment_vt;
vector<int> comb_vt;

int get_distanct(int y1, int y2, int x2, int x1)
{
    return ((y2-y1) * (y2-y1)) + ((x2-x1) * (x2-x1));
}

void input()
{
    cin >> K >> R;
    cin >> M;

    for(int i=0; i< M; i++)
    {
        restaurant temp_restaurant;
    
        cin >> temp_restaurant.y >> temp_restaurant.x;
        
        restaurant_vt.push_back(temp_restaurant);
    }

    cin >> N;

    for(int i=0; i< N; i++)
    {
        apartment temp_apartment;
    
        cin >> temp_apartment.y >> temp_apartment.x >> temp_apartment.cnt;
    
        apartment_vt.push_back(temp_apartment);
    }

}

int get_cnt()
{
    int temp_cnt = 0;

    for(int i = 0; i < comb_vt.size(); i++)
    {
        for(int j = 0; j < restaurant_vt[comb_vt[i]].apartment_vt.size(); j++)
        {
            int apartment_y = restaurant_vt[comb_vt[i]].apartment_vt[j].y + 1000;
            int apartment_x = restaurant_vt[comb_vt[i]].apartment_vt[j].x + 1000;
            
            if(visit[apartment_y][apartment_x] == false)
            {
                visit[apartment_y][apartment_x] = true;
                temp_cnt += restaurant_vt[comb_vt[i]].apartment_vt[j].cnt;
            }
        }
    }

    // visit 초기화
    for(int i = 0; i < comb_vt.size(); i++)
    {
        for(int j = 0; j < restaurant_vt[comb_vt[i]].apartment_vt.size(); j++)
        {
            int apartment_y = restaurant_vt[comb_vt[i]].apartment_vt[j].y + 1000;
            int apartment_x = restaurant_vt[comb_vt[i]].apartment_vt[j].x + 1000;

            visit[apartment_y][apartment_x] = false;
        }
    }

    return temp_cnt;
}

void go(int dep, int idx)
{
    if(dep == K)
    {
        // 조합된 집합에 해당 하는 아파트의 인원 카운트.
        int temp_cnt = get_cnt();

        ans = max(ans, temp_cnt);

        return;
    }

    for(int i = idx; i < restaurant_vt.size(); i++)
    {
        comb_vt.push_back(i);
        go(dep+1, i+1);
        comb_vt.pop_back();
    }


}

void solution()
{
    // 각 후보지마다 유효 거리에 있는 아파트의 좌표 인원을 포함.
    for(int i  = 0; i < restaurant_vt.size(); i++)
    {
        for(int j = 0; j < apartment_vt.size(); j++)
        {
            if(get_distanct(restaurant_vt[i].y, apartment_vt[j].y, restaurant_vt[i].x, apartment_vt[j].x) <= (R*R))
            {
                restaurant_vt[i].apartment_vt.push_back(apartment_vt[j]);
            }
        }
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