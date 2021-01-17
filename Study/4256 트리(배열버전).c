#include<stdio.h>

int T, n;
int preOrder[1001];
int inOrder[1001];

void init()
{
	for (int i = 0; i < 1001; i++)
	{
		preOrder[i] = 0;
		inOrder[i] = 0;
	}
}
void makeNode(int preLeft, int preRight, int inLeft, int inRight)
{
	if (preLeft > preRight)
		return;

	int leftCnt = 0;
	for (int i = inLeft; i <= inRight; i++)
	{
		if (preOrder[preLeft] == inOrder[i])
		{
			break;
		}
		leftCnt++;
	}

	//좌측 자식 노드와 우측 자식노드 할당
	makeNode(preLeft + 1, preLeft + leftCnt, inLeft, inLeft + leftCnt - 1);
	makeNode(preLeft + leftCnt + 1, preRight, inLeft + leftCnt + 1, inRight);
	printf("%d ", preOrder[preLeft]);
}

int main()
{
	scanf("%d", &T);

	while (T--)
	{
		init();
		scanf("%d", &n);

		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &preOrder[i]);
		}

		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &inOrder[i]);
		}
		makeNode(1, n, 1, n);
		printf("\n");
	}

	return 0;
}
