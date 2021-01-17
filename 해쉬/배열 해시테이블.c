#include<stdio.h>

int HashTable[10][1];

int hash(int id)
{
	return id % 10;
}
void addKey(int key)
{
	int bucket = hash(key);

	if (HashTable[bucket][0] == 0)
	{
		HashTable[bucket][0] = key;
	}
}

int findKey(int key)
{
	int bucket = hash(key);

	if (HashTable[bucket][0] == key)
		return 1;
	return 0;
}

int main()
{
	int num;
	int data;
	int ret;
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &num);
		addKey(num);
	}
	scanf("%d", &data);
	
	ret = findKey(data);

	if (ret != 0)
	{
		printf("data의 키값을 찾았습니다: %d\n",hash(data));
	}
	else
	{
		printf("해당 키 값을 찾을 수 없습니다\n");
	}
	
	return 0;
}
