#include<iostream>
#include<string>
#include<cstdio>
#include<vector>

using namespace std;

vector<string>::iterator iter;

int main()
{
	int N;

	while (cin >> N && N != 0)
	{
		char Top[1000][81], Bottom[1000][81];
		int TopIdx = 0, BottomIdx = 0;

		if (N % 2 == 0) //짝수
		{
			//상단 절반 저장 및 하단 절반 저장
			for (int i = 0; i < N; i++)
			{
				if (i < N / 2)
				{
					scanf(" %s", Top[TopIdx++]);
				}
				else
				{
					scanf(" %s", Bottom[BottomIdx++]);
				}
			}
			TopIdx = 0;
			BottomIdx = 0;
			int flag = 1;

			for (int i = 0; i < N; i++)
			{
				if (flag == 1)
				{
					printf("%s\n", Top[TopIdx++]);
					
				}
				else
				{
					printf("%s\n", Bottom[BottomIdx++]);
				}
				flag *= -1;
			}
		}

		else //홀수
		{
			//상단 절반 저장 및 하단 절반 저장
			for (int i = 0; i < N; i++)
			{
				if (i <= N / 2)
				{
					scanf("%s\n", Top[TopIdx++]);
				}
				else
				{
					scanf("%s\n", Bottom[BottomIdx++]);
				}
			}
			TopIdx = 0;
			BottomIdx = 0;
			int flag = 1;

			for (int i = 0; i < N; i++)
			{
				if (flag == 1)
				{
					printf("%s\n", Top[TopIdx++]);

				}
				else
				{
					printf("%s\n", Bottom[BottomIdx++]);
				}
				flag *= -1;
			}
		}
	}
}