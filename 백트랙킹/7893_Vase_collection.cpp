/*
   <백트래킹 - subset, 조합>

   1. for(k= 10 부터 1까지 ) pickup 갯수 설정 
      1-1. shape_mask[shape] |= (1ULL << deco) 형태로 모양별 장식 마스크 저장.
      1-2. 모양별 장식 마스크에서 공통 장식이 k개 이상인 경우만 후보군으로 저장.
   2. 모양과 장식을 탐색 go(0, 0xFFFFFFFFFFFFFFFF, k)
      2-1. 모양 탐색 (모양들의 공통 장식 찾기)
         go(int dep, ull shape_subset, int pickup_count)
         {
            if(shape_subset == pickup_count)
            {
               //pickup_count개 업데이트
               
               return;
            }

            if(이미 모든 탐색이 끝난 경우 || 나머지는 모두 포함해도 pickup_count개가 아닌 경우)
            {
            
               return;
            }

            //현재 모양 선택

            //현재 모양 미선택


         }
      
   3. 위 조합이 존재하면 k 값 출력.   


*/


#include <iostream>
#include <algorithm>
#include <vector>

#define pop_count __builtin_popcountll
#define ull unsigned long long

using namespace std;

int n, m;
ull shape_arr[37];
bool search_flag = false;

vector<ull> candidate_vt;

void init()
{
    search_flag = false;
    
    for(int i=0; i < 37; i++)
    {
        shape_arr[i] = 0;
    }
}

void input()
{
    cin >> m;

    for(int i=0; i < m; i++)
    {
        int shape, decoration;

        cin >> shape >> decoration;

        shape_arr[shape] |= (1ULL << (decoration - 1));


    }
}

void go(int dep, ull shape_subset, int pickup_count, int size)
{
    //pruining
    if(search_flag == true) return;

    //base case
    if(pickup_count == size)
    {
        if(pop_count(shape_subset) >= size)
        {
            search_flag = true;
        }
        return;
    }

    //pruning
    if(dep == candidate_vt.size()) 
    {
        return;
    }


    //현재 모양을 선택하는 경우
    ull new_shape_subset = (candidate_vt[dep] & shape_subset);
    
    if(pop_count(new_shape_subset) >= size)
    {
        go(dep + 1, new_shape_subset, pickup_count+1, size);
    }
    //shape_subset = (candidate_vt[dep] | shape_subset); //선택한 모양의 장식은 모두 포함
    
    //현재 모양을 선택하지 않은 경우
    go(dep + 1, shape_subset, pickup_count, size);

}

void solution()
{
    for(int k=10; k >= 1; k--)
    {
        int candidate_cnt = 0;
        candidate_vt.clear();

        //후보군 갯수 및 후보군 생성
        for(int i=0; i < 37; i++)
        {
            if(pop_count(shape_arr[i]) >= k)
            {
                candidate_cnt++;
                candidate_vt.push_back(shape_arr[i]);
            }
        }

        if(candidate_cnt < k) continue; //후보군이 k개보다 적으면 다음 k 탐색

        go(0, 0xFFFFFFFFFFFFFFFF, 0, k);

        if(search_flag)
        {
            cout << k << '\n';
            break;
        }
    }
}


int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    while(n--)
    {
        init();
        input();
        solution();

    }
    
    return 0;
}