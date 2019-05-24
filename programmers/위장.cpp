#include <string>
#include <vector>

using namespace std;
int  a[30], visit[30];
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int len = clothes.size();
    
    for(int i=0;i<len;i++){
        for(int j = i;j<len; j++){
            if(visit[j]) continue;
            if(clothes[i][1] == clothes[j][1]) {
                a[i]++;
                visit[j]++;
            }
        }
    }
    for(int i=0;i<len;i++){
        if(a[i]>0) answer *= a[i]+1;
    }
    return answer - 1;
}
