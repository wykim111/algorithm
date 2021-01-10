#include<stdio.h>

int arr[4] = {1,2,3,4};
int retArray[100];
int ret = 0;

void subset(int cnt,int dep,int curIdx)
{
    if(cnt == 4)
    {
        for(int i=0;i<dep;i++)
        {
           printf("%d ",retArray[i]);
        }

        ret++;
        
        printf("\n");
        return;
    }


    retArray[dep] = arr[curIdx];
    subset(cnt+1,dep+1,curIdx+1);//선택하는 경우
    subset(cnt+1,dep,curIdx+1);//선택 안 하는 경우
}


int main()
{
    subset(0,0,0);

    printf("총 갯수:%d\n",ret);

    return 0;
}
