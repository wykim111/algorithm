#include<stdio.h>
#include<stdlib.h>
int nums[] = { 1,0,-1,0,-2,2 };
int ret[100];

int cmp(const void* p1, const void* p2)
{
	int n1 = *(int*)p1;
	int n2 = *(int*)p2;


	return n1 - n2;
}

void go(int idx, int curIdx, int target, int sum)
{
	if (idx == 4)
	{
		if (sum == 0)
		{
			for (int i = 0; i < idx; i++)
			{
				printf("%d ", ret[i]);
			}
			printf("\n");
		}
		return;
	}

	for (int i = curIdx; i < 6; i++)
	{
		ret[idx] = nums[i];
		go(idx + 1, i + 1, 0, sum + nums[i]);
	}
}

int main()
{
	qsort(nums,sizeof(nums)/sizeof(nums[0]),sizeof(int),cmp );
	go(0,0,0,0);
}
