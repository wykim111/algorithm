/*
	���������� �Ϲ������� �ش� ���ڰ� ����� ������ ã�� ����
	������ ������ ����Ŀ� ���� ���� ������ ����

	������ ����� ��� target���� ũ�� ���
	������ ������ ��� target���� ������ ���
*/
#include<stdio.h>

int  main()
{
	while (1)
	{
		int num1, num2, target;
		int an = 0, d = 0;
		int i = 1;

		scanf("%d %d %d", &num1, &num2, &target);

		if (num1 == 0 && num2 == 0 && target == 0)
			break;

		//����
		d = num2;
		
		for (int i = 1;; i++)
		{
			an = num1 + ((i - 1)*d);

			//target�� ������ ��� ��� (������ ���� ����� ���)
			if (d > 0 && an > target)
			{
				printf("X\n");
				break;
			}
			else if(d < 0 && an < target)
			{
				printf("X\n");
				break;
			}

			//target�� ��ġ�ϴ� ���
			if (target == an)
			{
				printf("%d\n", i);
				break;
			}
		}
	}

	return 0;
}