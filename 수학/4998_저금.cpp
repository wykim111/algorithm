#include <stdio.h>
#include <math.h>

double N,B,M;

void solution()
{
    double sum = N;
    int ans = 0;

    while(sum < M)
    {
        sum += (sum * (B*0.01));


        ++ans;
    }

    printf("%d\n",ans);

}

int main()
{
    while(scanf("%lf %lf %lf",&N,&B,&M) != EOF)
    {
        //printf("%lf %lf %lf\n",N,B,M);
        solution();
    }

    return 0;
}
