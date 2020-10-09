/*
    1. 맞았다가 틀리면 다시 1점부터 계산
    2. 2개이상 연속으로 맞으면 1점 2점 순으로 점수를 높여서 계산

    seq변수를 이용하여 맞은 경우 현재 점수 += seq
    틀린 경우 seq는 0으로 초기화

    if(test[idx] == 1)
    {
        seq++;

        total += seq;

    }
    else //틀린 경우
    {
        seq = 0;
    }

*/
#include<stdio.h>

int N;
int test[101];

int main()
{
    int total = 0,seq = 0;

    scanf("%d",&N);

    for(int i=0;i<N;i++)
    {
        scanf("%d",&test[i]);
    }

    for(int i=0;i<N;i++)
    {
        if(test[i] == 1)
        {
            seq++;
            total += seq;
        }
        else
        {
            seq = 0;
        }
    }

    printf("%d\n",total);
    
    return 0;
}
