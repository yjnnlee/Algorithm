#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
/*int dx[] = {1,0,1}; //오른쪽, 아래, 오른쪽아래
int dy[] = {0, -1,-1};
int chk[1000][1000];*/

/*int dfs(int y,int x, vector<vector<int>> board, vector<vector<int>>chk, int answer){
        if(board[y+dy[0]][x+dx[0]] == 1 &&
           board[y+dy[1]][x+dx[1]] == 1 &&
           board[y+dy[2]][x+dx[2]] == 1){
//           x+1<board.size() && y+1 < board[0].size()){
            dfs(y)
        }
    return answer;
}*/

/*int solution(vector<vector<int>> board) {
    int answer = 1;
    vector<vector<int>> chk(board.size(), vector<int>());
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            if(board[i][j] == 1){
//                int tmp = dfs(i,j,board,chk, answer);
                int tmp = 0;
                for(int k = 1;;k++){
                    for(int p=i;p<=i+k;p++){
                        for(int q=j;q<=j+k;q++){
                            if(board[p][q] != 1) goto out;
                            else tmp++;
                        }
                    }
                }
out:           
                if(tmp>answer) answer = tmp;
            }
        }
    }

    return answer;
}*/


int solution(vector<vector<int>> board) {
    int answer = 1;
    for(int i=1;i<board.size();i++){ //0번째 줄은 어차피 해당 없음, 만약 거기에 1이 있다고 해도 최대 1인 정사각형일 것이며
        for(int j=1;j<board[i].size();j++){ //그러면 answer기본값 1이 출력됨
            if(board[i][j] && 
               board[i][j-1] && board[i-1][j] && board[i-1][j-1]){ //지금 위치가 1이면서 왼쪽, 왼쪽위, 위가 1 이상이면
                board[i][j] = min(min(board[i][j-1],board[i-1][j]),board[i-1][j-1])+1; //셋 중에 최소값+1로 현재값을 해줌
                //왜냐면 가장 작은 길이가 정사각형이기 때문, +1은 본인 포함하면 변의 길이가 1 늘어나니까
                if(board[i][j]>answer) answer = board[i][j];
                //배열 전체 수 중에 가장 큰 값이 정답이다
            }
        }
    }
    int zero_chk = 0; //반례->배열에 0밖에 없을 경우 answer은 0이다
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            zero_chk+=board[i][j];
        }
    }
    if(zero_chk == 0) return 0;
    return answer*answer;
}
