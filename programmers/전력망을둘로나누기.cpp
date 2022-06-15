#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

vector<bool> visit;
int map[101][101];
int dfs(int now, int n){ // 길이 재기
    if(visit[now]==1) return 0;
    int cnt = 1;
    visit[now] = 1;
    for(int i=1;i<=n;i++){
        if(map[now][i]){
            cnt += dfs(i,n);
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    for(int i=0;i<wires.size();i++){
//        tree[wires[i][0]].push_back(wires[i][1]);
//        tree[wires[i][1]].push_back(wires[i][0]);
        int a = wires[i][0];
        int b = wires[i][1];
        map[a][b] = 1;
        map[b][a] = 1;
    }
    for(int i=0;i<wires.size();i++){
//        tree[wires[i][0]][wires[i][1]] = -1;
//        tree[wires[i][1]][wires[i][0]] = -1;
        int a = wires[i][0];
        int b = wires[i][1];
        map[a][b] = 0;
        map[b][a] = 0;
        visit = vector<bool> (n+1, false);
                vector<int> diff;

        for(int j=1;j<=n;j++){
        int go = dfs(j, n);
        if(!go) continue;
        diff.push_back(go);
        }
        
        answer = min(answer, abs(diff[0]-diff[1]));
        if(answer ==0) break;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    
    return answer;
}
