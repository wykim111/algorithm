/*

1.해당유닛의 첫 위치 인덱스를 배정하는 기능을 추가할지 고려중....
2.규칙 생성, 비숍같은 경우 한 라인에 한개만 위치
3. 퀸 위주로 완성

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PrintMap(int **map, int n);//배치도 출력

int Set_Queen(int **map, int n, int x, int y);//퀸 경로
int Set_Knight(int **map, int n, int x, int y);//나이트 경로
int Set_Bishop(int **map, int n, int x, int y);//비숍 경로

int Recursive_Queen(int **map, int n, int line, int* caseNum);//퀸이 놓일 수 있는 위치와 경우의 수, 최초의 배치도를 저장하는 기능
int Findposition_Queen(int **map, int n, int* caseNum);//퀸의 경우의 수 반환

int Recursive_Bishop(int **map, int n, int line, int bishopNum, int* caseNum); // 비숍이 놓일 수 있는 위치와 경우의 수, 최초의 배치도를 저장하는 기능
int Findposition_Bishop(int **map, int n, int* caseNum);//비숍 경우의 수 반환


void PrintMap(int **map, int n)
{
	int count, x, y;

	for (y = 0; y<n; y++)
	{
		for (x = 0; x<n; x++)
		{
			if ((*map)[y*n + x] == 0)
				printf("□");
			else
				printf("●");
		}
		printf("\n");
	}
}

int Set_Queen(int **map, int n, int x, int y)
{
	int count;
	//거리를 늘려가며 체크
	for (count = 0; count<n; count++)
	{
		//우향 체크
		if (x + count < n)
		if ((*map)[y*n + (x + count)] != 0)
			return 0;
		//좌향 체크
		if (x - count >= 0)
		if ((*map)[y*n + (x - count)] != 0)
			return 0;
		//하향 체크
		if (y + count < n)
		if ((*map)[(y + count)*n + x] != 0)
			return 0;
		//상향 체크
		if (y - count >= 0)
		if ((*map)[(y - count)*n + x] != 0)
			return 0;

		//우하로 체크
		if (x + count < n && y + count < n)
		if ((*map)[(y + count)*n + (x + count)] != 0)
			return 0;
		//우상으로 체크
		if (x + count < n && y - count >= 0)
		if ((*map)[(y - count)*n + (x + count)] != 0)
			return 0;
		//좌하로 체크
		if (x - count >= 0 && y + count < n)
		if ((*map)[(y + count)*n + (x - count)] != 0)
			return 0;
		//좌상으로 체크
		if (x - count >= 0 && y - count >= 0)
		if ((*map)[(y - count)*n + (x - count)] != 0)
			return 0;
	}
	return 1;
}

int Set_Knight(int ** map, int n, int x, int y)
{
	int xCount, yCount;
	//메모리 할당
	*map = (int*)malloc(sizeof(int)* n * n);

	//맵 초기화
	for (yCount = 0; yCount < n; yCount++)
	{
		for (xCount = 0; xCount < n; xCount++)
			(*map)[yCount*n + xCount] = 0;
	}
	if (x - 2 >= 0 && y - 1 >= 0)
		(*map)[(y - 1)*n + (x - 2)] = 1;
	if (x - 2 >= 0 && y + 1 < n)
		(*map)[(y + 1)*n + (x - 2)] = 1;

	if (x - 1 >= 0 && y - 2 >= 0)
		(*map)[(y - 2)*n + (x - 1)] = 1;
	if (x - 1 >= 0 && y + 2 < n)
		(*map)[(y + 2)*n + (x - 1)] = 1;


	if (x + 2 < n && y - 1 >= 0)
		(*map)[(y - 1)*n + (x + 2)] = 1;
	if (x + 2 < n && y + 1 < n)
		(*map)[(y + 1)*n + (x + 2)] = 1;

	if (x + 1 < n && y - 2 >= 0)
		(*map)[(y - 2)*n + (x + 1)] = 1;
	if (x + 1 < n && y + 2 < n)
		(*map)[(y + 2)*n + (x + 1)] = 1;

	return 1;

}

int Set_Bishop(int **map, int n, int x, int y)
{
	int count;
	//거리를 늘려가며 체크
	for (count = 0; count<n; count++)
	{
		//우하로 체크
		if (x + count < n && y + count < n)
			if ((*map)[(y + count)*n + (x + count)] != 0)
				return 0;
		//우상으로 체크
		if (x + count < n && y - count >= 0)
			if ((*map)[(y - count)*n + (x + count)] != 0)
				return 0;
		//좌하로 체크
		if (x - count >= 0 && y + count < n)
			if ((*map)[(y + count)*n + (x - count)] != 0)
				return 0;
		//좌상으로 체크
		if (x - count >= 0 && y - count >= 0)
			if ((*map)[(y - count)*n + (x - count)] != 0)
				return 0;
	}
	return 1;

	
}

int Recursive_Queen(int **map, int n, int line, int* caseNum)
{
	int count, lineset;
	//line값이 n이 되는 의미는 모든 말이 각 라인에 놓아졌다는 의미이며, 이는 하나의 안정적인 패턴이 완성되었음을 의미
	if (line == n)
	{
		if (*caseNum == 0 || *caseNum <= 10)
		{
			printf("%d번쨰\n", *caseNum + 1);
			PrintMap(map, n);
			printf("\n");
		}
		(*caseNum)++;
		return 1;
	}
	else
	{
		for (count = 0; count<n; count++)
		{
			//현재 line 0으로 세팅
			for (lineset = 0; lineset<n; lineset++)
				(*map)[line*n + lineset] = 0;

			//현재 놓아야할곳에 놓아지는지 체크하고 놓아지면 1로 세팅 후 다음줄 진행, 안놓아지면 다음칸 체크
			if (Set_Queen(map, n, count, line))
				(*map)[line*n + count] = 1;
			else
				continue;

			//배치된 말이 서로 공격하지 않는 경우 다음 줄에 배치 진행
			Recursive_Queen(map, n, line + 1, caseNum);

		}
		//현재 line 0으로 세팅
		for (lineset = 0; lineset<n; lineset++)
			(*map)[line*n + lineset] = 0;
	}
	return 0;
}
int Recursive_Bishop(int **map, int n, int line, int bishopNum, int* caseNum)
{
	int count, lineset, lim;

	//bishopNum값이 n이 되는 의미는 모든 말이 각 라인에 놓아졌다는 의미이며, 이는 하나의 안정적인 패턴이 완성되었음을 의미
	if (bishopNum >= n)
	{
		if (*caseNum == 0 || *caseNum <= 27)
		{
			printf("%d번쨰\n", *caseNum + 1);
			PrintMap(map, n);
			printf("\n");
		}
		(*caseNum)++;
		return 1;
	}
	else if (line > n*(n - 1) + bishopNum)// 라인수 초과시 재귀 호출 종료
	{
		return 0;
	}
	else
	{
		lim = n*n;
		for (count = line; count<lim; count++)
		{
			if (bishopNum == n - 1 && 0)
			{
				PrintMap(map, n);
				printf("\n");
			}
			//현재 놓아야할곳에 놓아지는지 체크하고 놓아지면 1로 세팅 후 다음줄 진행, 안놓아지면 다음칸 체크
			if (Set_Bishop(map, n, count%n, count / n))
			{
				(*map)[count] = 1;

				//배치된 말이 서로 공격하지 않는 경우 다음 줄에 배치 진행
				Recursive_Bishop(map, n, count + 1, bishopNum + 1, caseNum);
				(*map)[count] = 0;
			}
			else
				continue;

		}
	}
	return 0;
}


int Findposition_Queen(int **map, int n, int* caseNum)
{
	int x, y;
	//메모리 할당
	*map = (int*)malloc(sizeof(int)* n * n);

	//맵 초기화
	for (y = 0; y < n; y++)
	{
		for (x = 0; x < n; x++)
		{
			(*map)[y*n + x] = 0;

		}
	}
	//답을 찾기위한 재귀 진행
	Recursive_Queen(map, n, 0, caseNum);
	free(*map);
	return *caseNum;
}

int Findposition_Bishop(int **map, int n, int* caseNum)
{
	int x, y;
	//메모리 할당
	*map = (int*)malloc(sizeof(int)* n * n);

	//맵 초기화
	for (y = 0; y < n; y++)
	{
		for (x = 0; x < n; x++)
		{
			(*map)[y*n + x] = 0;

		}
	}
	//답을 찾기위한 재귀 진행
	Recursive_Bishop(map, n, 0, 0, caseNum);
	free(*map);
	return *caseNum;
}
int main()
{
	
	clock_t time;
	int* map = 0;
	int n = 0; 
	char sel;
	int x, y;
	int queenCaseNum = 0, BishopCaseNum = 0;

	do
	{
		printf(" q 혹은 Q 입력시 N-Queen, k 혹은 K 입력시 Knight-Attack, B 혹은 b 입력시 N-Bishop, -1입력시 종료, 그외는 재입력 : ");
		scanf("%c", &sel); getchar(); //\n 제거
		
		if (sel == 'q' || sel == 'Q')//퀸
		{
			printf("n값을 입력하세요 : ");
			scanf("%d", &n);
			getchar();

			queenCaseNum = 0;//반복실행으로 이전의 데이터를 초기화
			
			time = clock();
			Findposition_Queen(&map, n, &queenCaseNum);
			time = clock() - time;
			
			if (queenCaseNum)
			{
				printf("경우의 수 : %d\n", queenCaseNum);
				printf("프로그램의 수행시간: %f \n", (double)time / CLOCKS_PER_SEC);
			}
			else
			{
				printf("해당 조건에서 맞는 배치를 찾을 수 없습니다\n");
			}
			printf("\n");
		}
		else if (sel == 'k' || sel == 'K')//나이트
		{
			printf("n값을 입력하세요 : ");
			scanf("%d", &n);
			getchar();
			printf("x의 값을 입력 : ");
			scanf("%d", &x);
			getchar();
			printf("y의 값을 입력 : ");
			scanf("%d", &y);
			getchar();

			if (Set_Knight(&map, n, x, y))
			{
				printf("<<<<<<>>>>>>>>>>>>>>>>>>>>\n");
				PrintMap(&map, n);
				free(map);

			}
			else
			{
				printf("잘못 배치\n");

			}



		}
		
		else if (sel == 'b' || sel == 'B')//비숍
		{
			printf("n값을 입력하세요 : ");
			scanf("%d", &n);
			getchar();

			BishopCaseNum = 0;//반복실행으로 이전의 데이터를 초기화
			
			time = clock();
			Findposition_Bishop(&map, n, &BishopCaseNum);
			time = clock() - time;

			if (BishopCaseNum)
			{
				printf("경우의 수 : %d\n", BishopCaseNum);
				printf("프로그램의 수행시간: %f \n", (double)time / CLOCKS_PER_SEC);
			}
			else
			{
				printf("해당 조건에서 맞는 배치를 찾을 수 없습니다\n");
			}
			printf("\n");

		}
		
		else if (sel == 'E' || sel == 'e')
		{
			printf("프로그램 종료\n");
			break;
		}
	
		else
		{
			printf("잘못된 입력입니다. \n");
		}
	} while (sel < -1 || sel > 1);

	//getchar();
	return 0;
}


