/*
    <백트래킹 - subset>

    1. 입력받은 문자열과 target 문자열이 주어짐
    2. 입력받은 문자열에서 target 문자열을 만들 수 있는지 여부를 구하여, 카운트.
    3. 탐색
        3-1. 입력받은 문자열의 각 문자에 대해서, target 문자열의 각 문자와 비교
        3-2. 일치하는 문자가 있다면, 다음 문자로 넘어가서 탐색
        3-3. 일치하는 문자가 없다면, 다음 문자로 넘어가서 탐색
    4. 탐색이 끝났을 때, target 문자열의 모든 문자가 일치하는 경우, 카운트 증가
================================================================================

    1. 탐색(가지치기)
        go(dep, subset_str, target_idx)
        {
            if(target_idx == target_str_size)
            {
                ans = (ans+1) % 10000;

                return;
            }
        
            if(dep == input_str.size())
            {
                return;
            }

            //가지치기 1 : subset_str의 길이가 target_str의 길이보다 큰 경우
            if(subset_str.size() > target_str.size())
            {
                return;
            }
            
            //가지치기 2 : subset_str의 마지막 문자가 target_str의 마지막 문자와 일치하는 경우
            if(input_str[dep]  == target_str[target_idx])
            {
                //현재 문자를 추가하는 경우
                go(dep+1, subset_str+input_str[dep], target_idx+1);
     
            }
            
           
            //현재 문자를 추가하지 않은 경우
            go(dep+1, subset_str, target_idx);
        }    

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>

#include <climits>

using namespace std;

int tc = 1;
int N;
string input_str;
const string target_str = "welcome to code jam";

int ans = 0;

void init()
{
    input_str.clear();
    ans = 0;
}

void input()
{
    getline(cin, input_str);

#if 0
    cout << "input : " << input_str << '\n';
    cout << "target : " << target_str << '\n';
#endif
    
}

void go(int dep, string subset_str, int target_idx)
{
    if(target_idx == target_str.size())
    {
        ans = ((ans + 1) % 10000);
        
        return;
    }

    //입력한 문자열을 전부 탐색한 경우
    if(dep == input_str.size())
    {
        return;
    }

    //현재 input_str의 dep번째 문자와 target_str의 target_idx번쨰 문자와 같은지 체크
    if(input_str[dep] == target_str[target_idx])
    {
        //현재 input_str의 dep 번째 문자를 선택한 경우
        go(dep+1, subset_str + input_str[dep], target_idx+1);
        
    } 

    //현재 input_str의 dep 번째 문자를 선택하지 않은 경우
    go(dep+1, subset_str, target_idx);

}

void solution()
{
    string ans_str = "";
    int zero_len = 0;

    go(0, "", 0);

    ans_str = to_string(ans);

    //4자릿수만 출력해야 하므로 3자리 이하인 경우 앞의 자릿수에 '0'을 채워줌.
    zero_len = (4 - ans_str.size());

#if 0
    for(int i=0; i < zero_len ; i++)
    {
        ans_str = "0" + ans_str;
    }
    

    cout << "Case " << "#" <<  tc << ": " << ans_str << '\n';
#endif

    cout << "Case #" << tc++ << ": " << setfill('0') << setw(4) << ans << '\n';
    

    
}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin.ignore();

    while(N--)
    {
        init();
        input();
        solution();
    }

    return 0;
}
