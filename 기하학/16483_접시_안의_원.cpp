/*
    < 기하학 - 피타고라스 정리>

    1. 현의 길이를 활용한 피타고라스 정리

        -> b^2 + (T/2)^2 = a^2
        -> (a^2) - (b^2) = (T/2)^2 


*/

#include <cstdio>
int main() 
{
    long long T;
 
    scanf("%lld", &T);
 
    printf("%lld\n", T * T / 4);
 
    return 0;
}
