#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
	int num;
	struct _node* left;
	struct _node* right;
}Node;

int T, n;
int preOrder[1001];
int inOrder[1001];
int priorityOrder[1001];

void init()
{
	for (int i = 0; i < 1001; i++)
	{
		preOrder[i] = 0;
		inOrder[i] = 0;
	}
}

Node* makeTree(int left, int right)
{
	if (left > right)
		return NULL;
	int min = 0;
	int minIdx = 0;
	int minOrder = 1e9;
	for (int i = left; i <= right; i++)
	{
		int temp = inOrder[i];

		if (minOrder > priorityOrder[temp])
		{
			minOrder = priorityOrder[temp];
			minIdx = i;
			min = temp;
		}
	}
	Node* root = (Node*)malloc(sizeof(Node));
	root->num = min;
	root->left = makeTree(left, minIdx - 1);
	root->right = makeTree(minIdx+1, right);

	return root;
}
void postOrder(Node* node)
{
	if (node->left != NULL)
		postOrder(node->left);

	if (node->right != NULL)
		postOrder(node->right);
	printf("%d ", node->num);
}

int main()
{
	scanf("%d", &T);

	while (T--)
	{
		Node* root;
		init();
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &preOrder[i]);
			priorityOrder[preOrder[i]] = i + 1;
		}

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &inOrder[i]);
		}
		root = makeTree(0,n-1);
		postOrder(root);
		printf("\n");
	}
}