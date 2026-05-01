/*
    <문자열>

단 한 번의 스캔 ($O(M)$): 문자열 $S$를 인덱스 $i$로 쭉 훑습니다.
IOI 카운팅: S[i], S[i+1], S[i+2]가 I-O-I 패턴인지 확인합니다.
연속성 유지: 맞다면 i += 2를 해서 다음 OI가 나오는지 계속 셉니다.
카운트 초기화: 패턴이 깨지면 다시 i++를 하며 다음 I를 찾습니다.


*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N, M;
string S;

void input()
{
    cin >> N;
    cin >> M;
    cin >> S;
}

void solution()
{
    string src_str = "I";
    int str_size = 0;
    int cnt = 0;

    for(int i=0; i < N; i++)
    {
        src_str += "OI";
    }

    str_size = src_str.size();
    //cout << "src_str = " <<  src_str << '\n';

    for(int start=0; start < S.size()-2; start++)
    {
        if(S[start] == 'I' && S[start+1] == 'O' && S[start+2] == 'I')
        {
            //src_str과 매칭 여부
            //매칭 되는 경우, start를 마지막 'I' 이전 인덱스로 이동
#if 0
            if(src_str == S.substr(start,str_size))
            {
                //cout << "prev start = " << start << '\n';
                ++cnt;
                start += 1; //다음 "IO" 문자 이동. 왜냐하면 마지막 문자를 기준으로 패턴 매칭 해야 함.
                //cout << "after start = " << start << '\n';
            }
#endif
            int seq_count = 0;

            while(S[start+1] == 'O' && S[start+2] == 'I')
            {
                ++seq_count;

                if(seq_count >= N)
                {
                    ++cnt;
                }

                start += 2;

                if(start >= S.size())
                {
                    break;
                }

            }

        }
    }

    cout << cnt << '\n';

}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solution();

    return 0;
}
