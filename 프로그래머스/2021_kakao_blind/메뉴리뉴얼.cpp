#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <map>


using namespace std;

map<string,int> mp[11];
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
