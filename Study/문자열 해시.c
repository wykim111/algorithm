/*
	Ű�� ���ڿ��� ������ ���� ���ϴ� ���������� �ٲٴ� �Լ��� �����(�ƽ�Ű�ڵ� ����)
	�ش� Ű�� �����ϴ� ���� ���

*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct _hash
{
	char* LastName;//�̸�
}Hash;

Hash Person[100];


void Init()
{
	for (int i = 0; i < 100; i++)
	{
		Person[i].LastName = NULL;
	}
}

void lower(char* key)
{
	int strLen = strlen(key);

	for (int i = 0; i < strLen; i++)
	{
		if (key[i] >= 'A' && key[i] <= 'Z')
		{
			key[i] += 32;
		}
	}
}
/*
	hashing
*/
int convertFistName(char* key)
{
	int strLen = strlen(key);
	int sum = 0;
	char tempKey[10];

	strcpy(tempKey, key);
	lower(tempKey);

	//printf("%s", tempKey);
	for (int i = 0; i < strLen; i++)
	{
		sum = (sum*10) + tempKey[i] - 'a';
	}

	return sum%100;
}

int insert(int Key,char* lastName)
{
	//���� �Ҵ� ���� ���
	if (Person[Key].LastName == NULL)
	{
		int LastNameLen = strlen(lastName);
		Person[Key].LastName = (char*)malloc(sizeof(char)* LastNameLen);

		strcpy(Person[Key].LastName, lastName);
	}
	else
		return -1;

	return 1;
}

int Search(char* name)
{
	int Key = convertFistName(name);

	if (Person[Key].LastName == NULL)
	{
		return -1;
	}
	printf("firstName = %s, last Name %s\n", name, Person[Key].LastName);
	
	return Key;
}
int main()
{
	char first[10],last[10];
	int Key;
	char SearchName[10];

	Init();


	for (int i = 0; i < 3; i++)
	{
		fgets(first, sizeof(first), stdin);
		first[strlen(first) - 1] = '\0';

		fgets(last, sizeof(last), stdin);
		last[strlen(last) - 1] = '\0';
		Key = convertFistName(first);
		printf("key = %d\n", Key);
		insert(Key, last);
		//printf("%s hash key =%d\n", str, Key);
	}
	fgets(SearchName, sizeof(SearchName), stdin);
	SearchName[strlen(SearchName) - 1] = '\0';


	if (Search(SearchName) == -1)
	{
		printf("��Ī�Ǵ� �����Ͱ� �����ϴ�\n");
	}
	else
	{
		printf("last Name %s\n", Person[Search(SearchName)].LastName);
	}


	return 0;
}
