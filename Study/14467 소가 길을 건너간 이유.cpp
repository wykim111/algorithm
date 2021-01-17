/*
	���� ���¿��� �ٸ� ���·� ���ϸ� �Ұ� ���� �ǳʰ����Ƿ� ī��Ʈ(0 -> 1, 1 - > 0)
	�� ���� id, ���� ���� ,�̵�Ƚ���� �����ϴ� ����ü ����
	�Է¹��� ���¿� ���� ���°� �����ϸ� ������Ʈ ������ ��ŵ

	�Ұ� ���� �Է� ���� ��� �̵�Ƚ���� 0�̸� ���� õ�̰� �Ͼ�� ī��Ʈ�Ͽ� �� ���� 0���� ũ�� ī��Ʈ�Ѵ�.
*/

#include<stdio.h>

#define LEFT 0
#define RIGHT 1

int N;


typedef struct _Cow
{
	int cowName; //�� �̸�
	int state; //�� ���� ����
	int cnt; // �� �̵� Ƚ��
}Cow;

Cow localCow[101];

void init()
{
	for (int i = 0; i < 101; i++)
	{
		localCow[i].cowName = i;
		localCow[i].state = -1;
		localCow[i].cnt = -1;
	}
}
int main()
{
	int curState,cowName;
	int sum = 0;
	
	
	init();
	
	
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &cowName, &curState);

		
		//���� �� �� �ǳ� ���¿� �Է� ���� ���°� �ٸ��� ����
		// ������ ��ŵ
		if (localCow[cowName].state != curState)
		{
			localCow[cowName].state = curState;
			localCow[cowName].cnt++;
		}
		else
		{
			continue;
		}
	}
	//�ǳʰ� Ƚ�� �� ī��Ʈ
	for (int i = 1; i <= N; i++)
	{
		//printf("%d %d %d\n", localCow[i].cowName, localCow[i].state, localCow[i].cnt);

		if (localCow[i].cnt > 0)
		{
			sum += localCow[i].cnt;
		}
	}
	printf("%d\n", sum);

	return 0;
}