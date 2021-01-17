#include <stdio.h>
#include <limits.h>
#define S_MAX 49999
int resultArray[S_MAX];

// �ű���_ å�� �ڵ�� �޸� ������� �ʾ�����, ����� ������ �޸� �����
// ������ �����մϴ�.
// ����� �� �ݾ׸��� �޸� �����ؾ� �ϴ� �� ������ �޸� ����� �������� ��
// �ֽ��ϴ�. ���� �� (���ɼ��� ������) 1�� ���� ���ؼ� ����� �ؾ� �ϸ� 
// sizeof(int) * 1�︸ŭ�� �޸𸮰� �ʿ��մϴ�.
// ���⼭�� 49999���� �������� �����ϰ� �ֽ��ϴ�.

int minCoins(int *coin, int N, int S)
{
	// ���� ����
	if (S == 0)
		return 0;

	if (resultArray[S] != -1)
		return resultArray[S];

	// �ּڰ��� �����ϴ� �����Դϴ�.
	int result = INT_MAX;
	for (int i = 0; i < N; i++)
	{
		// �׸鰡�� S���� ���ų� ���� ��� ������ ���ؼ� ��� ȣ���մϴ�.
		if (coin[i] <= S)
		{
			int temp = minCoins(coin, N, S - coin[i]);

			// ���ݱ��� �ּڰ����� �� ������ �ּڰ��� ��ü
			if (temp + 1 < result)
				result = temp + 1;
		}
	}
	resultArray[S] = result;
	return result;
}

int main()
{
	int coin[] = { 1, 5, 10, 50, 100, 500, 1000, 5000, 10000, 50000 };
	int N = sizeof(coin) / sizeof(int);
	int S = 65;
	for (int i = 0; i <= S; i++)
		resultArray[i] = -1;
	printf("%d���� ������ �� �ּ� ������ ������ %d���Դϴ�.\n", S, minCoins(coin, N, S));
	return 0;
}