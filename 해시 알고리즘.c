#include<stdio.h>
#include<string.h>

typedef struct person
{
	int id;
	char name[30];
}Person;

Person student[100];

void wy_strcpy(char* str1, char* str2)
{
	int len2 = strlen(str2);
	int i;
	for (i = 0;i <= len2; i++) // NULL���� ����
	{
		str1[i] = str2[i];
	}
}

int hash(int copy_id)
{
	return copy_id % 10;
}

int find_key(int copy_id)
{
	int bucket = hash(copy_id);

	if (copy_id == student[bucket].id)
	{
		return 1;
	}
	return 0;
}
int main()
{
	char stu_name[30];
	int stu_id;
	int bucket;
	int Find_ID;
	int N;

	printf("�л��� �� �Է�:");
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		memset(stu_name, 0, sizeof(stu_name));
		printf("�л���id�� �̸��� �Է��ϼ���\n");
		scanf("%d %s", &stu_id, &stu_name);

		while (getchar() != '\n');

		bucket = hash(stu_id);
		student[bucket].id = stu_id;
		wy_strcpy(student[bucket].name, stu_name);
	}
	
	printf("����\n");
	for (int i = 0; i < 100; i++)
	{
		if(student[i].id != 0)
			printf("�ؽ�:%d ID: %d �̸�:%s\n", hash(student[i].id), student[i].id, student[i].name);
	}
	
	
	printf("\nã����� ID �Է�:");
	scanf("%d", &Find_ID);
	if (find_key(Find_ID) == 1)
	{	
		bucket = hash(Find_ID);
		printf("��Ī�Ǵ� Ű ����:%s\n", student[bucket].name);
	}
	else
		printf("��ġ�ϴ� id�� �����ϴ�\n");


	return 0;
}