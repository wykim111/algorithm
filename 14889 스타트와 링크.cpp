/*
	1. s[i][j]�� s[j][i]�� �ٸ��� ����
	2. ���� �ɷ�ġ�� ���� ���� ��� ���� �ɷ�ġ ��
	3. i�� ����� j�� ����� ���� ���� ������ �� ���� �������� �ɷ�ġ�� 
	   s[i][j]�� s[j][i]
	4.�����̿������ ���� ���������� ���� ����ϴ� ����� ������ ������� �ٽ� �ѹ� �����غ���!!!!!!!!!!
*/
#include<stdio.h>
#include<math.h>
int N;
int s[21][21];
int Team[21];
int visit[21];
int ret[21];
int cnt = 0;
int minRet = 1e9;

int min(int n1, int n2)
{
	if (n1 > n2)
		return n2;

	return n1;
}

void comb(int idx,int curIdx)
{
	
	//���� ������ ���
	if (idx == N/2)
	{
		int start = 0;
		int link = 0;
		int temp;
		/*
		//����
		for (int i = 0; i < idx; i++)
		{
			printf("%d ", ret[i]);
		}
		printf("\n");
		*/
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (visit[i] == 1 && visit[j] == 1)
					start += s[i][j];
				if (visit[i] == 0 && visit[j] == 0)
					link += s[i][j];
			}
		}
		temp = abs(start - link);

		minRet = min(minRet, temp);


		return;
	}


	for (int i = curIdx; i < N; i++)
	{
		if (visit[i] == 1)
			continue;
		//ret[idx] = Team[i];
		visit[i] = 1;
		comb(idx+1,i+1);
		visit[i] = 0;
	}
}
int main()
{

	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &s[i][j]);
		}
	}
	
	//��ŸƮ���� ��ũ������ ����
	//������ ����
	comb(0,1);
	//printf("cnt = %d\n", cnt);

	printf("%d\n", minRet);
	return 0;
}