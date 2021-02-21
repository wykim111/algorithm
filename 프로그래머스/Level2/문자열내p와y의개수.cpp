/*
 s에 'p'의 개수와 'y'의 개수를 비교해 같으면 True, 다르면 False를 return 하는 solution를 완성하세요. 'p', 'y' 모두 하나도 없는 경우는 항상 True를 리턴
*/
#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int pCnt = 0;
    int yCnt = 0;
    
    for(int i=0;i<s.length();i++)
    {
        if(s.at(i) == 'p' || s.at(i) == 'P' )
        {
            pCnt++;
        }
        
           if(s.at(i) == 'y' || s.at(i) == 'Y' )
        {
            yCnt++;
        }
    }
    
    if(pCnt != yCnt)
    {
        answer = false;
    }
   

    return answer;
}
