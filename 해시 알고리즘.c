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
	for (i = 0;i <= len2; i++) // NULL까지 복사
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

	printf("학생의 수 입력:");
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		memset(stu_name, 0, sizeof(stu_name));
		printf("학생의id와 이름을 입력하세요\n");
		scanf("%d %s", &stu_id, &stu_name);

		while (getchar() != '\n');

		bucket = hash(stu_id);
		student[bucket].id = stu_id;
		wy_strcpy(student[bucket].name, stu_name);
	}
	
	printf("검증\n");
	for (int i = 0; i < 100; i++)
	{
		if(student[i].id != 0)
			printf("해시:%d ID: %d 이름:%s\n", hash(student[i].id), student[i].id, student[i].name);
	}
	
	
	printf("\n찾고싶은 ID 입력:");
	scanf("%d", &Find_ID);
	if (find_key(Find_ID) == 1)
	{	
		bucket = hash(Find_ID);
		printf("매칭되는 키 존재:%s\n", student[bucket].name);
	}
	else
		printf("일치하는 id가 없습니다\n");


	return 0;
}