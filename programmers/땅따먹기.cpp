#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[100001][4];
int solution(vector<vector<int> > land)
{
    int answer = 0;
    dp[land.size()-1][0] = land[land.size()-1][0];
    dp[land.size()-1][1] = land[land.size()-1][1];
    dp[land.size()-1][2] = land[land.size()-1][2];
    dp[land.size()-1][3] = land[land.size()-1][3];
    
    for(int k=land.size()-2;k>=0;k--){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(i==j) continue;
                dp[k][i] = max(dp[k][i], land[k][i]+dp[k+1][j]);
            }
        }
    }
    for(int i=0;i<4;i++){
        if(answer<dp[0][i]) answer=dp[0][i];
    }   
    return answer;
}

/*
ABCD
1234
이렇게 수가 있을 때
A에 들어갈 최대 값은 A+2, A+3, A+4 중에 가장 큰 값이고 B,C,D도 그럼
그리고 위에서 어떤 경로로 내려왔든 A의 최댓값은 A+2, A+3, A+4 중에 하나임
그래서 DP를 거꾸로 세는 방법으로 채우면 된다

맨 처음에 DP 맨 아래줄 land값으로 채워주고(위의 예시로 치면 1234값을 미리 DP에 넣는 것
A~D를 1~4까지 다 도는데 i==j면 안되니까 패스
돌면서 A값이 A+2, A+3, A+4 보다 작으면 바꿔줌

*/
