#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
	int data;
	int move;
	struct _node* prev;
	struct _node* next;

}stNode;


stNode* head = NULL;
stNode* tail = NULL;
stNode* cur = NULL;
int N;

void init()
{
	head = (stNode*)malloc(sizeof(stNode));
	tail = (stNode*)malloc(sizeof(stNode));

	head->next = tail;
	head->prev = tail;

	tail->next = head;
	tail->prev = head;
}


void addNode(int num,int move)
{
	stNode* newNode =(stNode*)malloc(sizeof(stNode));

	if (head->next == NULL)
	{
		newNode->data = num;
		newNode->move = move;

		newNode->next = tail;
		newNode->prev = head;

		head->next = newNode;
		//최초 삽입 노드 이후 삽입 노드들이 연결할 수 있도록 주소 저장
		tail->prev = newNode;
	}
	else
	{
		newNode->data = num;
		newNode->move = move;

		newNode->next = tail;	
		newNode->prev = tail->prev;
		
		tail->prev->next = newNode;
		tail->prev = newNode;
		
	}

}

void iterList()
{
	stNode* cur = tail->prev;

	if (cur == NULL)
	{
		printf("no valid\n");
		return;
	}
	while (cur != head)
	{
		printf("%d\n", cur->move);
		cur = cur->prev;

	}
	
	/*
	int cnt = 0;
	while (cur != NULL && cnt < 5)
	{
		printf("%d\n", cur->data);
		cur = cur->prev;
		cnt++;

	}
	*/

}
// sign이 양인 경우  삭제한 노드의 이전으로 위치
// sign이 음인 경우 삭제한 노드의 다음으로 위치
void removeNode(int sign)
{
	stNode* delNode = cur;
	
	if (delNode == NULL)
	{
		printf("unValid Node\n");
		return;
	}

	//삭제할 노드를 기준으로 이전 노드로 이동하고 그 다음 노드를
	// 삭제할 노드의 다음 노드로 연결 시킨다.
	delNode->prev->next = delNode->next;
	delNode->next->prev = delNode->prev;

	if(sign > 0)
		cur = delNode->prev;//삭제한 노드의 이전 노드로 이동
	else if(sign < 0)
		cur = delNode->next;//삭제한 노드의 다음 노드로 이동



	free(delNode);

	return;
}

void Print()
{
	int inputCnt = 1;
	int cnt = 0;
	cur = head->next;
	printf("%d ", cur->data);

	while (inputCnt++ < N)
	{
		cnt = cur->move;
		removeNode(cnt);
		
		
		
		if (cnt >= 0)
		{
			for (int i = 0; i < cnt; i++)
			{
				cur = cur->next;

				if (cur == tail)
				{
					cur = head->next;
				}
			}
		}
		else//음수
		{
			for (int i = cnt; i < 0; i++) // 음수
			{
				cur = cur->prev;

				if (cur == head)
				{
					cur = tail->prev;
				}
			}
		}
		printf("%d ", cur->data);
	}
}


int main()
{
	int num;

	init();


	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num);

		addNode(i+1,num);
	}

	Print();

	//iterList();

	return 0;
}
