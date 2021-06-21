#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> vt;;
int n;
int target;
/*
void merge(int start, int mid, int end)
{
	int fIdx = start;
	int rIdx = mid + 1;
	int idx = start;
	int* temp = (int*)malloc(sizeof(int) * (end + 1));


	while (fIdx <= mid && rIdx <= end)
	{
		if (arr[fIdx] < arr[rIdx])
		{
			temp[idx] = arr[fIdx];
			fIdx++;
			idx++;
		}
		else
		{
			temp[idx] = arr[rIdx];
			rIdx++;
			idx++;
		}
	}
	//fIdx, rIdx 중 아직 정렬이 안된 포인터를 temp 배열에 채워준다
	if (fIdx <= mid)
	{
		for (int i = fIdx; i <= mid; i++)
		{
			temp[idx] = arr[i];
			idx++;
		}
	}
	else
	{
		for (int i = rIdx; i <= end; i++)
		{
			temp[idx] = arr[i];
			idx++;
		}
	}

	for (int i = start; i <= end; i++)
	{
		arr[i] = temp[i];
	}


}


void merge_sort(int start,int end)
{
	if (start < end)
	{
		int mid = (start + end) >> 1;

		merge_sort(start, mid);
		merge_sort(mid + 1, end);
		merge(start, mid, end);
	}

}
*/
int main()
{
	int left = 0, right = 0;
	int cnt = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);

		vt.push_back(num);
	}
	scanf("%d", &target);

	//merge_sort(0, n - 1);
#if 0
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
#endif

	sort(vt.begin(), vt.end());

	left = 0, right = n - 1;

	while (left < right)
	{
		if ((vt[left] + vt[right]) == target)
		{
			cnt++;
			left++;
		}
		else if ((vt[left] + vt[right]) < target)
		{
			left++;
		}
		else
		{
			right--;
		}
	}

	printf("%d\n", cnt);

	return 0;
}
