/*
	�л��� * (1���� 100)���� ���� �� �ش� ���� ��� �������� ������ �� ���� ���� �ִ�� ������ �� �������� �ǹ�
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;
vector<pair<int, int>> vt;
int remain[100];

int cntApple(int cnt)
{
	int multiple = 1;
	int numOfApple = 0;
	int flag = 0;

	//�и�(�л�)�� ����(���)���� ū ��� ����� ���� �״�� ��ȯ
	if (vt[cnt].first > vt[cnt].second)
		return vt[cnt].second;

	while (true)
	{
		int temp = vt[cnt].first * multiple;
		
		//����� �л����� ���� ���
		//�и�(�л�)�� ����(���)���� ū ��� �л������� ��� ������ �� �� �����Ͽ� Ż��
		if (temp > vt[cnt].second)
		{
			break;
		}
		numOfApple = vt[cnt].second % temp;

		multiple++;
	}
	return numOfApple;
}
int main()
{
	int N;
	int sum = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int student, apple;

		scanf("%d %d", &student, &apple);

		vt.push_back(make_pair( student,apple ));
	}
	/*
	for (vector<pair<int, int>>::iterator it = vt.begin(); it != vt.end(); it++)
		printf("%d %d\n", it->first, it->second);
	*/
	for (int i = 0; i < vt.size(); i++)
	{
		sum += cntApple(i);
		//printf("cntApple = %d\n", cntApple(i));
	}
	printf("%d\n", sum);

	return 0;
}