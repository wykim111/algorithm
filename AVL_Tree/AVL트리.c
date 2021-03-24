/*
	AVL 트리 - 균형 이진 탐색 트리
	- 각 노드에서 왼쪽 서브 트리의 높이와 오른쪽 서브 트리의 높이 차이가 1이하인 이진 탐색 트리

	LL 회전 : 경로상의 노드들을 오른쪽으로 회전
	LR 회전 : 경로상의 노드들을 왼쪽 - 오른쪽으로 회전
	RR 회전 : 경로상의 노드들을 왼쪽으로 회전
	RL 회전 : 경로상의 노드들을 오른쪽 - 왼쪽으로 회전

	참고 : http://egloos.zum.com/printf/v/913998

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node* left;
	struct _node* right;
}Node;

Node* root;


Node* balance_tree(Node** node)
{
	int heightDiff = getBalance(*node);
	
	//왼쪽 서브트리 균형을 맞춤
	if (heightDiff > 1)
	{
		if (getBalance((*node)->left) > 0)
		{
			*node = rotate_LL(*node);
		}
		else
		{
			*node = rotate_LR(*node);
		}
	}
	else if (heightDiff < -1)
	{
		if (getBalance((*node)->right) < 0)
		{
			*node = rotate_RR(*node);
		}
		else
		{
			*node = rotate_RL(*node);
		}
	}

	return *node;
}

Node* AVL_Insert(Node** root,int num)
{
	if (*root == NULL)
	{
		*root = (Node*)malloc(sizeof(Node));

		(*root)->data = num;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}

	else if (num < (*root)->data)
	{
		(*root)->left = AVL_Insert(&((*root)->left), num);
		(*root) = balance_tree(root);
	}
	else if (num > (*root)->data)
	{
		(*root)->right = AVL_Insert(&((*root)->right), num);
		(*root) = balance_tree(root);
	}


	return *root;
}




int main()
{
	AVL_Insert(&root, 8);

	return 0;
}
