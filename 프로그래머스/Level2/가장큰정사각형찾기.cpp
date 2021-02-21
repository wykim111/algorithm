/*
        기준점을 기준으로 왼쪽,위쪽,좌상에 1이 있는지 비교
        모두 존재하면 정사각형이므로 기준점 위치 +1 씩 업데이트
        단, 왼쪽, 위쪽, 좌상의 데이터 중 값이 다르면,셋 중 최소 값 +1로 업데이트
        
        -> 정사각형이므로 사각형이 1이면 길이가 1이고 2이면 길이가 2인 정사각형 의미
*/

#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    //행과 열의 길이를 구함
    int row = board.size();
    int col = board[0].size();
    
    //0,0부터 탐색했다면 맵을 벗어나는 예외처리를 추가해야하므로
    //(1,1)부터 시작
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            //현재 위치가 1이상이면 사각형 체크
            if(board[i][j] >= 1)
            {
                int up = board[i-1][j];
                int left = board[i][j-1];
                int upLeft = board[i-1][j-1];
                
                
                board[i][j] = min(min(up,left),upLeft)+1;
            }
        }
    }
    int maxData = -1;
    
     for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            if(maxData < board[i][j]) 
            {
                maxData = board[i][j];
            }
        }
         
     }
    
    answer = maxData*maxData;

    return answer;
}
