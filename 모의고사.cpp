#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//������� �Ű�����
vector<int> solution(vector<int> answers) {

	vector<int> answer;
	//�л� 1,2,3
	vector<int> stu1{ 1,2,3,4,5 };
	vector<int> stu2{ 2, 1, 2, 3, 2, 4, 2, 5 }; 
	vector<int> stu3{ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
	int Max_Point = 0;
	//�л��� ���� ������ ����
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;


	for (int i = 0; i < answers.size(); i++)
	{
		if (stu1[i%5] == answers[i])
			cnt1++;
		if (stu2[i%8] == answers[i])
			cnt2++;
		if (stu3[i%10] == answers[i])
			cnt3++;
	}

	//����
	Max_Point = max(cnt1, max(cnt2, cnt3));

	if (Max_Point == cnt1)
	{
		answer.push_back(1);
	}
	if (Max_Point == cnt2)
	{
		answer.push_back(2);
	}
	if (Max_Point == cnt3)
	{
		answer.push_back(3);
	}

	return answer;
}