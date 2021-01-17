#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{
	int answer = 0;
	int person[31];

	for (int i = 0; i <= 31; i++)
	{
		person[i] = 0;
	}

	for (int i = 0; i < lost.size(); i++)
	{
		person[lost[i]]--;
	}
	for (int i = 0; i < reserve.size(); i++)
	{
		person[reserve[i]]++;
	}

	//��ü Ž�� ����
	for (int i = 0; i < lost.size(); i++)
	{
		//�ջ���̳� �޻���� ������ �������� ���
		//���� �������� ������ �ִ� ���
		if (person[lost[i]] != -1)
			continue;
		//�ջ���� �ִ� ���
		if (person[lost[i] - 1] == 1)
		{
			person[lost[i]] = 0;
			person[lost[i]-1] = 0;
			
		}
		else if(person[lost[i]+1] == 1)//�޻���� ������ ����
		{
			person[lost[i]] = 0;
			person[lost[i] + 1] = 0;
		}

	}
	for (int i = 1; i <= n; i++)
	{
		if (person[i] != -1)
			answer++;
	}
	
	return answer;
}
