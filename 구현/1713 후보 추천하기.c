/*
학생들이 추천을 시작하기 전에 모든 사진틀은 비어있다.
어떤 학생이 특정 학생을 추천하면, 추천받은 학생의 사진이 반드시 사진틀에 게시되어야 한다.
비어있는 사진틀이 없는 경우에는 현재까지 추천 받은 횟수가 가장 적은 학생의 사진을 삭제하고, 그 자리에 새롭게 추천받은 학생의 사진을 게시한다. 이때, 현재까지 추천 받은 횟수가 가장 적은 학생이 두 명 이상일 경우에는 그러한 학생들 중 게시된 지 가장 오래된 사진을 삭제한다.
현재 사진이 게시된 학생이 다른 학생의 추천을 받은 경우에는 추천받은 횟수만 증가시킨다.
사진틀에 게시된 사진이 삭제되는 경우에는 해당 학생이 추천받은 횟수는 0으로 바뀐다.
후보의 수 즉, 사진틀의 개수와 전체 학생의 추천 결과가 추천받은 순서대로 주어졌을 때, 최종 후보가 누구인지 결정하는 프로그램을 작성하시오.

추천(사람번호) :  2  1  4		1 4 3		4 3 5	   3 5 6	5 6 2		6 2 7	      
	 추천수      (1)(1)(1)	   (1)(1)(1)   (1)(1)(1)  (1)(1)(1) (1)(1)(1)	(1)(2)(1)

	 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _leader
{
	int time;//시간
	int recommend;//추천받은 학생
	int recommendCnt; //추천 수
}leader;

leader Line[20];
int N;

int cmp(const void* p1, const void* p2)
{
	leader n1 = *(leader*)p1;
	leader n2 = *(leader*)p2;

	
	return n1.recommend - n2.recommend;
}

void forward(int start)
{
	for (int i = start; i < N - 1; i++)
	{
		Line[i] = Line[i + 1];
	}
}

int isSameRecommend(int size)
{
	for (int i = 0; i < size-1; i++)
	{
		if (Line[i].recommendCnt != Line[i + 1].recommendCnt)
			return 0;

	}
	return 1;
}



int add(int size)
{
	int lowRecommendCnt = 1234;
	int longTime = 1234;
	int idx = 0,startIdx = 0;
	//가장 낮은 추천수를 가진 오래된 후보
	//가장 낮은 추천수를 먼저 뽑음
	for ( idx = 0; idx < size; idx++)
	{
		if (lowRecommendCnt > Line[idx].recommendCnt)
		{
			lowRecommendCnt = Line[idx].recommendCnt;

		}
	}
	//가장 낮은 추천 수 중 가장 오래된 후보
	for (idx = 0; idx < size; idx++)
	{
		if (lowRecommendCnt == Line[idx].recommendCnt)
		{
			if (longTime > Line[idx].time)
			{
				longTime = Line[idx].time;
				startIdx = idx;
			}

		}
	}

	return startIdx;
}

int main()
{
	int cnt, time = 1;
	int idx = 0;

	scanf("%d", &N);
	scanf("%d", &cnt);

	while (cnt--)
	{
		int sameFlag = 0;
		int recommendStu;
		
		scanf("%d", &recommendStu);

		//리스트에 추천받은 학생이 있으면 카운트
		//없으면 리스트에서 오래되고 가장 낮은 추천 수를 제외

		//이미 같은 추천인이 있는 경우
		for (int i = 0; i < idx; i++)
		{
			if (Line[i].recommend == recommendStu)
			{
				sameFlag = 1;
				Line[i].recommendCnt++;
				break;
			}
			
		}
		
		if (sameFlag == 1)
			continue;

		//같은 추천인이 아닌 새 추천인을 추가하는 경우
		if (idx == N)
		{
			int startIdx = add(N);
			
			forward(startIdx);

			Line[idx-1].recommend = recommendStu;
			Line[idx-1].recommendCnt = 1;
			Line[idx-1].time = time;
			time++;
			continue;
		}


		Line[idx].recommend = recommendStu;
		Line[idx].recommendCnt++;
		Line[idx].time = time;
		idx++;
		time++;
	}
	/*
	//출력 확인
	for (int i = 0; i < N; i++)
	{
		printf("%d ", Line[i].recommend);
	}
	printf("\n");
	*/

	//추천수 정렬
	qsort(Line, N, sizeof(leader), cmp);

	for (int i = 0; i < idx; i++)
	{
		printf("%d ", Line[i].recommend);
	}

	return 0;
}
