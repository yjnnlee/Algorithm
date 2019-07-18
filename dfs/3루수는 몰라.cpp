#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int n, res = 0, cnt = 0, dy[2]={0,1},dx[2]={1,0};
char visit[501][501], map[501][101];
vector<char> v(501);

int dfs(int y, int x, int len){
	if(y==n-1 && x==n-1){
		for(int k=0;k<len;k++){
			if(v[k] == 'M') if(v[k+1] == 'O') if(v[k+2] == 'L') if(v[k+3] == 'A'){
				k+=4;
				cnt+=1;
			}
		}
		if(cnt>res) res = cnt;
		cnt = 0;
		len = 0;
	}
	
	for(int i = 0;i<2;i++){
		int newy = dy[i]+y;
		int newx = dx[i]+x;
		if(newy>=n||newx>=n) continue;
		if(!visit[map[newy][newx]-'A']){
			visit[map[newy][newx]-'A'] = 1;
			dfs(newy,newx,len+1);
			visit[map[newy][newx]-'A'] = 0;
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%s", map[i]);
	}
	dfs(0,0);
}
