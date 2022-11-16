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

int Max(int n1, int n2)
{
	if (n1 > n2)
		return n1;

	return n2;
}

//LL 회전
// 비유하자면 시계 12시를 바라보는 기준으로 왼쪽으로 돌린다.
// -2<=h <= 2를 가지는 A가 부모라면 A->left는 B라 가정
//A->left는 B이므로 B가 가지는 right를 가르키게 한다.
//B->right는 A를 가르킨다.
Node* rotateLL(Node* parent)
{
	Node* child = parent->left;
	parent->left = child->right;
	child->right = parent;

	return child;
}

//RR 회전
// 비유하자면 시계 12시를 바라보는 기준으로 오른쪽으로 돌린다.
// -2<=h<= 2를 가지는 A가 부모라면 A->right는 B라 가정
//A->right는 B이므로 B가 가지는 left를 가르키게 한다.
//B->left는 A를 가르킨다.
Node* rotateRR(Node* parent)
{
	Node* child = parent->right;
	parent->right = child->left;
	child->left = parent;

	return child;
}
//RL 회전 : 오른쪽 왼쪽 회전
// -2<=h<= 2를 가지는 A가 부모라면 A->right는 B라 가정
//A->right는 rotateLL(B)가 반환하는 값을 가르킴
//이후 rotateRR(A) 호출
Node* rotateRL(Node* parent)
{
	Node* child = parent->right;
	parent->right = rotateLL(child);
	
	return rotateRR(parent);
}
//LR 회전 : 왼쪽 오른쪽 회전
// -2<=h<= 2를 가지는 A가 부모라면 A->left는 B라 가정
//A->left는 rotateRR(B)가 반환하는 값을 가르킴
//이후 rotateLL(A) 호출
Node* rotateLR(Node* parent)
{
	Node* child = parent->left;
	parent->left = rotateRR(child);

	return rotateLL(parent);
}


int getHeight(Node* node)
{
	int height = 0;

	if (node != NULL)
	{

		return 0;
	}

	return height = 1 + Max(getHeight(node->left),getHeight(node->right));
}

int getBalance(Node* node)
{
	if (node == NULL)
		return 0;

	return getHeight(node->left) - getHeight(node->right);
}

Node* balance_tree(Node** node)
{
	int heightDiff = getBalance(*node);
	
	//왼쪽 서브트리 균형을 맞춤
	if (heightDiff > 1)
	{
		if (getBalance((*node)->left) > 0)
		{
			*node = rotateLL(*node);
		}
		else
		{
			*node = rotateLR(*node);
		}
	}
	else if (heightDiff < -1)
	{
		if (getBalance((*node)->right) < 0)
		{
			*node = rotateRR(*node);
		}
		else
		{
			*node = rotateRL(*node);
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

// 이진 트리의 탐색 함수
Node* avlSearch(Node *node, int key)
{
	if (node == NULL) return NULL;

	printf("%d->", node->data);

	if (key == node->data)
		return node;
	else if (key < node->data)
		avlSearch(node->left, key);
	else
		avlSearch(node->right, key);
}

int main()
{
	AVL_Insert(&root, 8);
	AVL_Insert(&root, 9);
	AVL_Insert(&root, 10);
	AVL_Insert(&root, 2);
	AVL_Insert(&root, 1);
	AVL_Insert(&root, 5);
	AVL_Insert(&root, 3);
	AVL_Insert(&root, 6);
	AVL_Insert(&root, 4);
	AVL_Insert(&root, 7);
	AVL_Insert(&root, 11);
	AVL_Insert(&root, 12);

	return 0;
}
