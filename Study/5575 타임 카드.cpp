/*
Ÿ��ī�忡�� ����ϴ� �ð������� 24 �ð����� ����Ѵ�.
��� ������ 23�� ������ ���
������ ��� �ð��� �׻� ��� �ð����� �ʴ�.
*/
#include<stdio.h>

int main()
{
	int sh, sm, ss, eh, em, es;

	for (int i = 0; i < 3; i++)
	{
		int ret1, ret2,ret3;
		int retH, retM, retS;

		scanf("%d %d %d %d %d %d", &sh, &sm, &ss, &eh, &em, &es);

		ret1 = (sh * 3600) + (sm * 60) + ss;
		ret2 = (eh * 3600) + (em * 60) + es;

		ret3 = ret2 - ret1;
		
		//�ð� : ret3 / 3600 
		//�� : (ret3 % 3600) / 60
		//�� : (ret3 % 3600) % 60

		printf("%d %d %d\n", ret3 / 3600, (ret3 % 3600) / 60, (ret3 % 3600) % 60);

	
	}
	return 0;
}