#include<stdio.h>

int chang = 100, sang = 100;
int N;
int dice1,dice2;

int main()
{
	scanf("%d", &N);

	while (N--)
	{
		//â�� ��� ��
		scanf("%d %d", &dice1, &dice2);
		//���� ���ڰ� ���� ����� ����� �ֻ����� ���� ���ڸ�ŭ ������ �Ұ� �ȴ�.
		if (dice1 > dice2)
		{
			sang -= dice1;
		}
		else if(dice1 < dice2)
		{
			chang -= dice2;
		}
		else
		{
			//blank
		}

	}
	printf("%d\n%d\n", chang, sang);

	return 0;
}


