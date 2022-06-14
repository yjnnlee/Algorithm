#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool visit[1000];
int n;
int answer = 0;

void dfs(vector<vector<int>> &dungeons, int now, int tired, int depth){
    visit[now] = true;
    tired -= dungeons[now][1]; // 던전 들어옴
    for(int i=0;i<n;i++){
        if(!visit[i] && tired>=dungeons[i][0]) dfs(dungeons, i, tired, depth+1); //depth++ 은 위험한 것임 절대 사용하지 말 것
    }    
    answer = max(answer, depth);
    visit[now] = false;
    
}

int solution(int k, vector<vector<int>> dungeons) {
    n = dungeons.size();
    for(int i=0;i<n;i++){
        if(dungeons[i][0]<=k) dfs(dungeons, i, k, 1);
    }    
    
    return answer;
}

// DP인줄 알았으나 앞으로 정렬하든 뒤를 기준으로 정렬하든 1->3->2 같은 예시 확인 불가
// 어차피 범위도 작으니 완전탐색 dfs나 bfs사용
