/*
  입력된 문자열을 ","를 기준으토 트콘 분히한다. 
  문자열을 숫자로 파싱한 뒤에 모두 더한다.
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


char str[101];

int main()
{
    char* pStr = NULL;
    int sum = 0;
    scanf("%s",str);

    pStr = strtok(str,",");

    sum += atoi(pStr);

    while(pStr = strtok(NULL,","))
    {
        sum += atoi(pStr);
    }

    printf("%d\n",sum);


    return 0;
}
