#include<iostream>
#include<cstring>
#include<map>
#include<algorithm>
#include <string>

using namespace std;

#define STR_SIZE 502
#define HASH_MUL 3
#define HASH_SIZE 10002
#define CPP_SUPPORT 1

#if (CPP_SUPPORT == 1)

map<string, bool> mp;

int main()
{
	int N, M;
	int cnt = 0;
	cin >> N >> M;


	while (N--)
	{
		string str;
		
		cin >> str;

		mp[str] = true;
	}
	while (M--)
	{
		string str;

		cin >> str;
		
		if (mp[str] == true)
		{
			cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;
}


#else
typedef struct _node
{
	char str[STR_SIZE];
	struct _node * next;
}stNode;

stNode* stHashTable[HASH_SIZE];
int N, M;


void Init()
{
	int i;

	for (i = 0; i < HASH_SIZE; i++)
	{
		stHashTable[i] = NULL;
	}
}

unsigned long getHash(char* str)
{
	unsigned long key = 0;
	int strLen = strlen(str);
	int i;

	for (i = 0; i < strLen; i++)
	{
		key += (str[i] * HASH_MUL) % HASH_SIZE;
	}

	return key;
}
void insert(char* pStr, unsigned long key)
{
	stNode* newNode = (stNode*)malloc(sizeof(stNode));
	
	if (newNode == NULL)
	{
		return;
	}
	strcpy(newNode->str, pStr);
	newNode->next = stHashTable[key];
	stHashTable[key] = newNode;
	
}

int find(char* pStr, int key)
{
	for (stNode* iter = stHashTable[key]; iter != NULL; iter = iter->next)
	{
		if (strcmp(iter->str, pStr) == 0)
		{
			return 1;
		}
	}
	return 0;
}

void delNode()
{
	int i = 0;

	for (i = 0; i < HASH_SIZE; i++)
	{
		free(stHashTable[i]);
	}
}

int main()
{
	char name[STR_SIZE];
	unsigned long key = 0;
	int cnt = 0;

	Init();

	scanf("%d %d", &N, &M);

	while (N--)
	{
		memset(name, 0, sizeof(name));
		scanf("%s", name);

		key = getHash(name);
		insert(name, key);
	}

	while (M--)
	{
		memset(name, 0, sizeof(name));
		scanf("%s", name);

		key = getHash(name);
		
		if (find(name,key) == 1)
		{
			cnt++;
		}

	}

	printf("%d\n", cnt);
	
	delNode();
	return 0;
}
#endif
