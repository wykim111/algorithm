/*
	- 이진 트리는 루트노드를 기준으로 작으면 left, 크면 right로 이동하여
	  노드를 추가하고자 하는 위치를 찾아 추가한다.
	
	참조 : https://www.crocus.co.kr/640

	ex. a < b < c 인 경우

	1) b를 삽입 : min = a, max = c
	   min의 오른 쪽 혹은  max의 왼쪽에 추가해야하는데 
	   min의 오른쪽은 이미 존재하므로, max의 왼쪽에 삽입

		a				a(root)
		   c				c
					      b

	2) c를 삽입 : min = b, max = x -> max가 없는 이유는 c보다 크면서 가까운 값이 없음
		a				a(root)
		   b				b
								c

	3) a를 삽입 : min = x, max = b -> min이 없는 이유는 a보다 작으면서 가까운 값이 없기 때문
	   min의 왼쪽 혹은 max의 오른쪽에 추가해야하나 min의 왼쪽이 비어있으므로 추가
		
			c				c
		b				b		
					a


*/

#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace std;


typedef struct _node
{
	int left;
	int right;
	long long int cnt;

}Node;

map<int, Node> mpTree;
map<int, Node>::iterator iter;
long long ret = 0;

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int num;
		int max = -1, min = -1;
		scanf("%d", &num);
		//첫번쨰로 들어오는 값은 root 노드
		if (i == 0)
		{
			mpTree[num].cnt = 0;
			printf("%lld\n", mpTree[num].cnt);
			continue;
		}

		iter = mpTree.end();
		iter--; //마지막에 추가한 노드를 가르킴

		//해당 입력 노드와 마지막에 추가한 노드를 비교하여
		//마지막에 추가한 노드보다 작으면 max에는 노드를 추가할 수 없고
		// min에 업데이트
		if (iter->first < num)
		{
			min = iter->first;
			max = -1;
		}
		else// 마지막 값이 입력한 값보다 큰 경우 
		{
			//lowerbound로 현재 들어온 값보다 크거나 같은 것 중
			//가장 가까운 값 탐색
			iter = mpTree.lower_bound(num);

			//iter가 tree의 처음을 가르키고 있는 경우
			//입력한 값이 mpTree에서 가장 작다는 의미로 min 설정 필요 x

			if (iter == mpTree.begin())
			{
				min = -1;
				max = iter->first;
			}
			/*
				iter가 처음위치가 아닌 경우는
				max는 현재 반복자가 가리키는 곳
				min은 현재 반복자가 가리키는 바로 이전 단계

			*/
			else
			{
				max = iter->first;
				iter--;
				min = iter->first;
			}
		}

		//min != -1 이고 max != -1인 경우
		//위 구간에 존재 하는 값임
		if (min != -1 && max != -1)
		{
			//max의 왼쪽에 노드가 없는 경우 추가
			if (mpTree[max].left == 0)
			{
				mpTree[max].left = num;
				mpTree[num].cnt = mpTree[max].cnt + 1;
			}
			//max의 왼쪽에 노드가 존재하는 경우
			//min의 오른쪽에 추가
			else
			{
				mpTree[min].right = num;
				mpTree[num].cnt = mpTree[min].cnt + 1;
			}

		}
		//max != -1로 
		else if (min == -1 && max != -1)
		{
			mpTree[max].left = num;
			mpTree[num].cnt = mpTree[max].cnt+1;

		}

		else if (min != -1 && max == -1)
		{
			mpTree[min].right = num;
			mpTree[num].cnt = mpTree[min].cnt + 1;
		}

		ret += mpTree[num].cnt;
		printf("%lld\n", ret);

	}
	


	return 0;
}
