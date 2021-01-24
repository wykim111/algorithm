#include<stdio.h>

int N;
int arr[1001];
int size;



int main()
{
	scanf("%d", &N);

	size = N;

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}

	int curPos = 1;
	int cnt = 0;
	int loop = 1;
	//printf("%d ", curPos);

	cnt = arr[curPos];
	arr[curPos] = 0;

	while (1)
	{
		int i;
		int movePos = 0;

		printf("%d ", curPos);

		if (loop >= size)
			break;

		//arr[i] = 0;


		//오프셋 : 상대 인덱스 위치 이동
		//이동위치가 양수인 경우
		if (cnt > 0)
		{
			for (movePos = 1; movePos <= cnt; )
			{
				
				curPos++;

				if (arr[curPos] == 0)
				{
					if (curPos == size)
					{
						curPos = 0;
					}

					continue;
				}


				if (curPos > size)
				{
					curPos = 0;
				}

				movePos++;
			}
		}
		else if (cnt < 0)
		{
			for (movePos = 1; movePos <= cnt * (-1);)
			{
				curPos--;

				if (arr[curPos] == 0)
				{
					if (curPos == 1)
					{
						curPos = size+1;
					}
					continue;
				}

				if (curPos == 0)
				{
					curPos = size+1;
				}


				movePos++;
			}
		}



		
		cnt = arr[curPos];
		arr[curPos] = 0;
		//curPos = movePos;
		

		loop++;
		
	}


	return 0;
}
