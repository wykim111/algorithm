/*
    메뉴에 대해 조합을 이용하여 완전 탐색을 한 뒤, 중복되는 메뉴에 대해 카운트
    - 각 메뉴를 오름차순으로 정리
    - 현재 메뉴를 선택하는 경우와 선택하지 않은 경우를 탑색하고, map을 이용하여 인덱스로 길이를 받고, 
      길이에 대한 음식의 구성을 키로 받은 뒤, value로는 카운트를 증가시킨다.

    
*/

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <map>


using namespace std;

map<string,int> mp[11];//  index는 조합을 통해 구성된 orders의 메뉴(key)의 길이 , value는 키에 대한 카운트
int maxTable[11];

void comb(int dep,string pick,string str)
{
    if(dep >= str.length())
    {
        int strLen = pick.length();
        
        if(strLen >=2)
        {
            mp[strLen][pick]++;
            
            if(maxTable[strLen] < mp[strLen][pick])
            {
                maxTable[strLen] = mp[strLen][pick];
            }
            
        }
        
        return;
    }
    
    
    comb(dep+1,pick+str[dep],str);
    comb(dep+1,pick,str);
    
}

bool cmp(string s1,string s2)
{
    return s1 < s2;//사전 순
}


vector<string> solution(vector<string> orders, vector<int> course) {
    
    
    for(string str : orders)
    {
        sort(str.begin(),str.end());
        comb(0,"",str);
    }
        
    vector<string> answer;
    
    for(auto Len : course)
    {
        for(auto iter : mp[Len])
        {
            if(iter.second >= 2 && iter.second == maxTable[Len])
            {
                answer.push_back(iter.first);
            }
        }
    }
    
    sort(answer.begin(),answer.end());
    
    return answer;
}
