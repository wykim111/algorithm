#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>



char* solution(int n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    //한글은 2Byte이기 때문에 2를 곱했지만, 실패했고
    //3을 곱한 힙영역은 통과. 왜일까나..
    char* answer = (char*)malloc(sizeof(char)*((3*n)+1));
    int idx = 0;
    
    memset(answer,0,sizeof(answer));
    //Modular 0~1씩 순환
    for(int i=0;i<n;i++)
    {
        if(i%2 == 0)
        {
              strcat(answer,"수");
        }
        else
        {
              strcat(answer,"박");
        }
      
    }
    
    
    return answer;
}
