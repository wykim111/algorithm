#include<stdio.h>
#include<math.h>

int N;
int map[15];//�ε����� Row�� �ǹ�, �ش��ϴ� �����ʹ� Col�� �ǹ�
int sum = 0;

int threat(int Row)
{
	int cur_Row = 0;

	while (cur_Row < Row)
	{
		//�밢��-> ���� �밢�� �� ���� �밢��
		//����
		if (abs(cur_Row - Row) == abs(map[cur_Row] - map[Row]) ||((map[cur_Row]- map[Row])== 0) )
		{
			return 1;
		}
		cur_Row++;
	}
	return 0;
}

void find_Queen(int Row,int cnt)
{
	//���� ������ �ִ��� Ȯ��
	if (threat(Row) == 1)
	{
		return;
	}
	else if (Row == N-1)
	{
		sum++;
		return;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			map[Row + 1] = i;
			find_Queen(Row+1,cnt+1);
		}
	}
}


int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		map[0] = i;//0�࿡ �ش��ϴ� col�� ����
		find_Queen(0, 0);
	}
	printf("%d\n", sum);
	
	return 0;
}