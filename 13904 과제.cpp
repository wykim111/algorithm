#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int maxday = 0;
int res = 0;

typedef struct _work
{
	int d;//���� ������ ���� ���� �ϼ�, ������ ���� ��
	int w;//������ ���� ��
}Work;

Work homework[1000];
bool visit[1000] = { 0, };

bool cmp(Work& p1, Work& p2)
{
	//�������� ����
	return p1.w > p2.w;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		//int d, w;//���� ������ ���� ���� �ϼ�, ������ ���� ��
		
		scanf("%d %d", &(homework[i].d), &(homework[i].w));
		maxday = max(homework[i].d, maxday);
	}
	//���������� ��������
	sort(homework + 0, homework + N, cmp);
	/*
	printf("���ļ���\n");

	for (int i = 0; i < N; i++)
	{
		printf("%d %d\n", homework[i].d, homework[i].w);
	}
	printf("maxday = %d\n", maxday);
	*/
	
	for (int i = maxday; i >= 1; i--)
	{
		for (int j = 0; j < N; j++)
		{
			if (homework[j].d >= i && visit[j] == 0)
			{
				visit[j] = 1;
				res += homework[j].w;
				break;
			}
		}
	}

	printf("%d\n", res);

	return 0;
}