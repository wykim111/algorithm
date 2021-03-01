#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    //현재 pos에서 pos+1부터 pos+(N-1)까지 탐색
    //이미 같은  값이 존재하면 넘어가고 없으면 추가
    for(int i=0;i<numbers.size()-1;i++)
    {
        
        
        for(int j=i+1;j<numbers.size();j++)
        {
            int sum = numbers[i] + numbers[j];
            bool flag = false;//중복값 존재 여부
            
            for(vector<int>::iterator iter = answer.begin();iter != answer.end();iter++)
            {
                if(*iter == sum)//중복값 존재하면 true
                {
                    flag = true;        
                    break;
                }
            }//for iter
            
            //중복값이 존재하는 경우
            if(flag == true)
            {
                continue;
            }
            
            answer.push_back(sum);
            
        } // for j
    } //for i
    
    sort(answer.begin(),answer.end());
    
    return answer;
}
