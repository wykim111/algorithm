/*
	1. 숫자 10개를 42로 나눈 나머지를 구하고 배열에 저장
	2. 오름차순 정렬
	3. 정렬한 뒤, 같은 수가 뒤에 있으면 계속 스킵하고 다른수가 나올 때까지
	   반복한다.
	4. 다른 수가 나오면 다른 수 카운트를 증가시키고 3~4 반복한다
*/

/*
	이 문제 이렇게 위와 같이 풀지 말고 다음 방법으로 풀어본다
	arr[n%42]++로 해당 인덱스에 접근해서 카운트를 하여
	arr[n%42]가 0이 아닌 경우만 카운트하면 끝

*/
#include<stdio.h>

int remainder(int n)
{

	return n % 42;
}
void bubbleSort(int* a,int size)
{
	
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			int temp;
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int arr[10];
	int ret[10];
	int idx = 0;
	for (int i = 0; i < 10; i++)
	{
		int num;

		scanf("%d", &num);

		arr[i] = remainder(num);
	}
	/*
	//출력
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		printf("arr[%d]= %d\n", i, arr[i]);
	}
	*/
	bubbleSort(arr,10);
	int ptr1, ptr2;
	//for문 조건문에 의해 마지막 수와 그 이전 값이 같은 경우
	//조건 검사 초과가 되어 넘어감
	//다른 경우
	// 
	for (ptr1 = 0; ptr1 < 10; ptr1++)
	{
		int flag = 1; //마지막 원소 체크
		for (ptr2 = ptr1 + 1; ptr2 < 10; ptr2++)
		{
			if (arr[ptr1] != arr[ptr2])
			{
				break;
			}
		}
		//inner for문에는 서로 다른 수를 가르키며, out for문에는 증감식이 있으므로
		// 1감소 시켜준다.
		ptr1 = ptr2 - 1;
		ret[idx++] = arr[ptr1];
		//마지막 원소 저장
	
	}
	/* 원소 체크
	for (int i = 0; i <idx; i++)
	{
		printf("arr[%d]= %d\n", i, ret[i]);
	}
	*/
	printf("%d\n", idx);

	return 0;

}
