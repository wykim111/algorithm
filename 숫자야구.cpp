#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> baseball) {
	int answer = 0;
	int strike = 0;
	int out = 0;
	int ball = 0;
	int flag = true;
	string Pick_NUM;
	string Input_NUM;

	for (int i = 123; i <= 987; i++) {
		Pick_NUM = to_string(i);
		if (Pick_NUM[0] == Pick_NUM[1] || Pick_NUM[0] == Pick_NUM[2] || Pick_NUM[1] == Pick_NUM[2])
			continue;
		else if (Pick_NUM[0] == '0' || Pick_NUM[1] == '0' || Pick_NUM[2] == '0')
			continue;
		flag = true;
		for (int j = 0; j < baseball.size(); j++) {
			strike = 0;
			ball = 0;
			for (int a = 0; a < 3; a++) {
				for (int b = 0; b < 3; b++) {
					Input_NUM = to_string(baseball[j][0]);
					if (a == b && Pick_NUM[a] == Input_NUM[b])
					{
						strike++;
						continue;
					}
					if (a != b && Pick_NUM[a] == Input_NUM[b]) {
						ball++;
						continue;
					}
				}//for b
			
			}//for a
			//out Á¶»ç
			for (int c = 0; c < 3; c++)
			{
				if (Input_NUM[0] != Pick_NUM[c] && Input_NUM[1] != Pick_NUM[c] && Input_NUM[2] != Pick_NUM[c])
				{
					out++;
				}
			}
			


			if (strike != baseball[j][1] || ball != baseball[j][2]) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			answer++;
		}


	}

	return answer;
}