/*
    3으로 나누어 나머지가 1이면 1, 2이면 2, 0이면 4를 붙임
    
*/
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int temp = n;
    
    while(temp != 0)
    {
        int remain =  temp % 3;
        temp /= 3;
        
        if(remain == 1)
            answer = '1' + answer;
        else if(remain == 2)
            answer = '2'+ answer;
        else if(remain ==0) //분자가 완전히 나누어 떨어지는 경우
        {
          answer ='4'+ answer;
            temp--;
        }
        
       
    }
    return answer;
}
