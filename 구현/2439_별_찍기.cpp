#include <iostream>
#include <algorithm>

using namespace std;

int N;

void input()
{
    cin >> N;
}

void solution()
{
    for(int i=1; i <= N; i++)
    {
        // 빈칸 출력
        for(int j=0; j < N-i; j++)
        {
            cout << " ";
        }

        // '*' 출력
        for(int j=0; j < i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}


int main()
{
    input();
    solution();
    
    return 0;
}