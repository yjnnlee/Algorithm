#include <stdio.h>
int r, c, dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 }, max = 0;
char map[25][25], chk[500];

void dfs(int y, int x, int res) {
	if (max < res) max = res;
	
	for (int i = 0; i < 4; i++) {
		int newy = dy[i] + y;
		int newx = dx[i] + x;
		if (newy<0 || newy>=r || newx<0 || newx >=c) continue;
		if (!(chk[map[newy][newx]-'A'])) {
			chk[map[newy][newx]-'A'] = 1;
			dfs(newy, newx, res+1);
			chk[map[newy][newx] - 'A'] = 0; 
			//경로가 여러개 있을 수 있고, 새로운 경로가 더 길 수도 있기 때문에 dfs가 끝난 이후에 방문 안 함으로 바꿔줘야됨
		}
	}
}

int main() {
	scanf("%d %d", &r, &c); //r이 세로 c가 가로
	for (int i = 0; i < r; i++) {
		scanf("%s", &map[i]);
	}
	chk[map[0][0]-'A'] = 1;
	dfs(0, 0, 1);
	printf("%d", max);
}
