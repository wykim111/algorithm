/*
벨트의 임의의 한 위치부터 k개의 접시를 연속해서 먹을 경우 할인된 정액 가격으로 제공한다.
 1번 행사에 참가할 경우 이 쿠폰에 적혀진 종류의 초밥 하나를 추가로 무료로 제공한다. 
 만약 이 번호에 적혀진 초밥이 현재 벨트 위에 없을 경우, 요리사가 새로 만들어 손님에게 제공한다.

 
 - 투 포인터 활용

 */

#include<stdio.h>

//접시의 수 N, 초밥의 가짓수 d, 연속해서 먹는 접시의 수 k, 쿠폰 번호 c
int N, d, k, c; 

int plate[30001];//접시의 수
int sushi[3001];//초밥
int cnt = 0, maxRet = -1;

int main()
{
	scanf("%d %d %d %d", &N, &d, &k, &c);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &plate[i]);
	}

	//투 포인터
	for (int i = 0; i < k; i++)
	{
		//처음 먹는 초밥
		if (sushi[plate[i]] == 0)
		{
			cnt++;
		}
		
		sushi[plate[i]]++;
	}

	maxRet = cnt;

	for (int i = 1; i < N; i++)
	{

		if (maxRet <= cnt)
		{
			//연속 4개 먹을 떄 c번을 먹어서 카운트 판단
			//처음 c개를 먹는 경우
			if (sushi[c] == 0)
			{
				maxRet++;
			}
			else
			{
				maxRet = cnt;
			}
		}


		//현재에서 다음 칸 이동 시 현재에 먹은거 뺌 
		sushi[plate[i-1]]--;

		//위와 같이 뺄 때 2개이상 먹은 게 아닌 경우
		//0개로 아에 먹지 않은 경우가 되므로
		if (sushi[plate[i-1]] == 0)
		{
			cnt--;
		}
		int next = (i + k - 1) % N;
		//다음칸으로 이동한 초밥이 처음 먹은 경우
		if (sushi[plate[next]] == 0)
		{
			cnt++;
		}
		sushi[plate[next]]++;

	}


	printf("%d\n", maxRet);


	return 0;
}
