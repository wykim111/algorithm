/*
    0. ù ���ڸ� �ε����� �Ͽ� �迭�� ī��Ʈ
	1. ù ���ڰ� 5�� �̻��̸� ���̺� �迭�� ����
	   ���̺� ���� ���� 5�� �̸��� ���	PREDAJA ��� �ϰ� ����
	2. ������������ ����

	����̰� ���� �ټ� ���� ������ �� ���� ��쿡�� "PREDAJA" (����ǥ ����)�� ����Ѵ�. PREDAJA�� ũ�ξ�Ƽ�ƾ�� �׺��� �ǹ��Ѵ�. 
	������ �� �ִ� ��쿡�� ������ ���� ù ���ڸ� ���������� ������� ��� ����Ѵ�.
*/
#include<stdio.h>
#include<string.h>

char name[150][32];
int N;
int firstName[26] = { 0, };
char nameTable[26];
int nameTableIdx = 0;

int pickName()
{
	int flag = 0;

	for (int i = 0; i < 26; i++)
	{
		if (firstName[i] >= 5)
		{
			nameTable[nameTableIdx++] = i + 'a';
			flag = 1;
		}
	}

	if (flag == 0)
	{
		return 0; //5�� �̸��� ���
	}

	return 1; //5�� �̻��� ���
}

void bubbleSort()
{
	for (int i = 0; i < nameTableIdx-1; i++)
	{
		for (int j = 0; j < nameTableIdx - 1 - i; j++)
		{
			if (nameTable[j] > nameTable[j + 1])
			{
				char temp = nameTable[j];
				nameTable[j] = nameTable[j + 1];
				nameTable[j + 1] = temp;
			}
		}
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", name[i]);
		while (getchar() != '\n');

		firstName[name[i][0] - 'a']++;
	}

	if (pickName() == 0)
	{
		printf("PREDAJA\n");
		
		return 0;
	}
	
	bubbleSort();

	for (int i = 0; i < nameTableIdx; i++)
	{
		printf("%c", nameTable[i]);
	}
	printf("\n");


	return 0;
}