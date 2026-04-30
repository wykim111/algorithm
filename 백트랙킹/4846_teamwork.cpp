/*
1. 전체 조각의 합을 구하여 3으로 나누어 값 설정.

2. 설정한 값을 target으로 두고 막대기 구성 여부 체크
   2-1. 막대기 구성하기 힘들면 1씩 감소하여, 막대기 구성 여부 체크.

3. 탐색 시작
//stick_dep : 막대기 번호
//dep : 막대기 번호에서 탐색하는 조각의 번호
//target : 막대기의 길이
//sum : 현재 막대기의 길이

go(stick_dep, dep, target, sum, stick_cnt)
{

   if(search_flag == true)
   {

      return;

   }



   if(stick_dep == 3)
   {

      search_flag = true;
      target 최댓값 업데이트

   }

   if(sum == target)
   {

      if(stick_cnt >= 2)
      {
         //접합점 누적 합 계산
         int acc_sum = stick_perm_vt[stick_dep][0];
         int stick_perm_size = stick_perm_vt.size();
         int flag = true;
         
         if(접합점이 다른 막대와 같은 경우)
         {
            return;
         }
         
         for(int i=1;i < stick_perm_size-1;i++)
         {
            stick_mp[acc_sum] = true;
            acc_sum += stick_perm_vt[i];
         }

         
      
         go(stick_dep+1, 0, target, 0, 0);
         
         acc_sum = stick_perm_vt[stick_dep][0];
         stick_perm_size = stick_perm_vt.size();
         
         for(int i=stick_perm_size-1;i > 0;i--)
         {
            stick_mp[acc_sum] = false;
            acc_sum -= stick_perm_vt[i];
            
         }
      }

      return;

   }



   if(dep == size)
   {
      return;
   }



   for(int i=0 ~ size)
   {

      int next_sum =  sum + stick_vt[i]

      if(이미 쓴 숫자이면)
         continue;


      if(next_sum이 target보다 큰 경우)
         continue;




      visit[i] = true;
      stick_perm_vt[stick_dep].push_back(stick_vt[i])

      go(stick_dep, dep+1,target, next_sum, stick_cnt+1);

      stick_perm_vt[stick_dep].pop_back();
      visit[i] = false;


   }





}
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m;
vector<int> stick_perm_vt[3];
vector<int> stick_vt;

bool stick_mp[40001];

bool visit[13];
bool search_flag = false;
int stick_total_sum = 0;
int t = 1;

void init()
{
      search_flag = false;
      stick_vt.clear();
      fill(stick_mp, stick_mp+40001, false);
      stick_total_sum = 0;
         
      for(int i=0; i < 3; i++)
      {
         stick_perm_vt[i].clear();
      }
   
      fill(visit, visit+13, false);
}

void input()
{
      for(int i=0; i < n; i++)
      {
         int stick_len;

         cin >> stick_len;

         stick_vt.push_back(stick_len);
         stick_total_sum += stick_len;
      }

      sort(stick_vt.begin(), stick_vt.end(), greater<int>());

}

void go(int stick_dep, int dep, int target, int sum, int stick_cnt)
{
   if(search_flag) return;

   if(stick_dep == 3) {
      search_flag = true;
      return;
   }

   if(sum == target) {
      if(stick_cnt >= 2) {
         int acc_sum = 0;
         int stick_perm_size = stick_perm_vt[stick_dep].size();
         bool flag = true;
         vector<int> temp_acc_sum_vt;         
         
         for(int i = 0; i < stick_perm_size - 1; i++) {
            acc_sum += stick_perm_vt[stick_dep][i];
            if(stick_mp[acc_sum]) {
               flag = false;
               break;
            }
            temp_acc_sum_vt.push_back(acc_sum);
         }
         
         if(flag) {
            for(int val : temp_acc_sum_vt) stick_mp[val] = true;
            go(stick_dep + 1, 0, target, 0, 0);
            for(int val : temp_acc_sum_vt) stick_mp[val] = false;
         }
      }
      return;
   }

   int last_len = -1; // [추가] 같은 길이 조각 중복 탐색 방지
   for(int i = 0; i < n; i++) {
      if(visit[i] || sum + stick_vt[i] > target) continue;
      
      // [핵심 최적화] 이전에 실패한 조각과 같은 길이면 스킵
      if(stick_vt[i] == last_len) continue;

      visit[i] = true;
      stick_perm_vt[stick_dep].push_back(stick_vt[i]);

      go(stick_dep, dep + 1, target, sum + stick_vt[i], stick_cnt + 1);

      // 복구
      stick_perm_vt[stick_dep].pop_back();
      visit[i] = false;
      last_len = stick_vt[i]; // 방금 시도한 길이를 기록

      if(search_flag) return;
      
      //if(sum == 0 || sum + stick_vt[i] == target) return;
   }
}
void solution()
{
  int target_len = stick_total_sum / 3;

    for (int i = target_len; i >= 1; i--) 
    {
   
        go(0, 0, i, 0, 0);

        if (search_flag) 
        {
            cout << "Case " << t << ": " << i << '\n';
            ++t;
            return;
        }
    }
    // 가능한 경우가 없으면 0 출력
    cout << "Case " << t << ": " << 0 << '\n';
    ++t;
}

int main()
{
   ios::sync_with_stdio(NULL);
   cin.tie(NULL);
   cout.tie(NULL);

   

   while(true)
   {
      cin >> n;

      if( n == 0)
      {
         break;
      }

      init();
      input();
      solution();
   
   }

   return 0;
}