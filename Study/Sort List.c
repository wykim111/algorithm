typedef struct ListNode List;
List* mergeTwoLists(List* left, List* right);
/* void printL(List* head); */

List* partition(List* head, int len)
{
	if (len <= 1) return head;
	List *rightHead, *leftTail = head; /* leftHead == head */
	/* first split into two lists */
	for (int i = 0; i < len / 2 - 1; i++)
		leftTail = leftTail->next;

	rightHead = leftTail->next;
	leftTail->next = NULL;
	List* leftTemp = partition(head, len / 2);
	List* rightTemp = partition(rightHead, len - len / 2);

	return mergeTwoLists(leftTemp, rightTemp);
}

List* sortList(List* head)
{
	if (head == NULL)
		return NULL;
	int len = 0;
	for (List* p = head; p; p = p->next)
		len++;
	return partition(head, len);
}

List* mergeTwoLists(List* left, List* right)
{
	if ((left == NULL) && (right == NULL))
		return NULL;
	else if (left == NULL)
		return right;
	else if (right == NULL)
		return left;

	if (left->val > right->val)
	{
		right->next = mergeTwoLists(left, right->next);
		return right;
	}
	else
	{
		left->next = mergeTwoLists(left->next, right);
		return left;
	}
	return NULL;
}

