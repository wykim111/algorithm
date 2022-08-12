#include<stdio.h>
#include<string.h>

#define MAX 10001

int N;

typedef struct _queue
{
	int front;
	int rear;
	int buffer[MAX];
	int numOfData;
}st_queue;

void Init(st_queue* Que)
{
	Que->front = 0;
	Que->rear = 0;
	Que->numOfData = 0;
}

int empty(st_queue* Que)
{
	if (Que->numOfData == 0)
	{
		return 1;
	}

	return 0;
}


void push(st_queue* Que, int n)
{
	Que->buffer[Que->rear++] = n;
	Que->numOfData++;

}
int pop(st_queue* Que)
{
	if (empty(Que))
	{
		return -1;
	}

	int data = Que->buffer[Que->front];

	Que->front++;
	Que->numOfData--;
	
	return data;
}

int front(st_queue* Que)
{
	if (Que->numOfData == 0)
	{
		return -1;
	}

	return Que->buffer[Que->front];
}

int back(st_queue* Que)
{
	if (Que->numOfData == 0)
	{
		return -1;
	}
	return Que->buffer[Que->rear-1];
}

int size(st_queue* Que)
{
	if (Que->numOfData < 0)
	{
		Que->numOfData = 0;
	}
	return Que->numOfData;
}
int main()
{
	char str[100];
	int i;
	int data;
	st_queue Que;

	scanf("%d", &N);

	Init(&Que);

	for (i = 0; i < N; i++)
	{
		scanf("%s", str);

		if (!strcmp(str, "push"))
		{
			scanf("%d", &data);
			push(&Que, data);

		}
		else if (!strcmp(str, "pop"))
		{
			printf("%d\n", pop(&Que));
			//cnt--;
		}
		else if (!strcmp(str, "empty"))
		{
			printf("%d\n", empty(&Que));
		}
		else if (!strcmp(str, "size"))
		{
			printf("%d\n", size(&Que));
		}
		else if (!strcmp(str, "front"))
		{
			printf("%d\n", front(&Que));
		}
		else if (!strcmp(str, "back"))
		{
			printf("%d\n", back(&Que));
		}
	}

	return 0;
}
