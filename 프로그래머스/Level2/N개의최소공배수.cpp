/*
   원소를 차례대로 하나씩 최대공약수를 구하고, 이 둘의 최소공배수를 업데이트 한다.
   단 주의할 것은 answer =1로 초기 값을 두고 하나씩 진행해야함.

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//최
int GCD(int n1,int n2)
{
    if(n2 == 0)
        return n1;
    
    return GCD(n2,n1%n2);
}
//최소공배수
int lcm(int n1,int n2)
{
    return n1*n2/GCD(n1,n2);
}
// arr_len은 배열 arr의 길이입니다.
int solution(int arr[], size_t arr_len) {
    int answer = 1;
    int gcdNum = 0;
    
   for(int i=0;i<arr_len;i++)
   {
       answer = lcm(answer,arr[i]);
   }
    
    
    return answer;
}
