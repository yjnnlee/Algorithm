#include <stdio.h>
int c, h, w, white = 0;
char map[35][35];
int covertype[4][3][2] = { //시작지점, y, x
	{ {0,0}, {1,0}, {0,1} }, //┌
	{ {0,0}, {0,1}, {1,1} }, //┐
	{ {0,0}, {1,0}, {1,1}}, //└
	{ {0,0}, {1,0}, {1,-1}} //┘
};
bool possible(int y, int x, int type, int sw) { //놓을 수 있는가?
	for (int i = 0; i < 4; i++) {
		int ny = y + covertype[type][i][0]; //1+0
		int nx = x + covertype[type][i][1]; //0+0
//		printf(">%d %d\n", ny, nx);
		if (ny < 0 || ny >= h || nx < 0 || nx >= w) return false; //넘으면 안 된다
		else if ((map[ny][nx] += sw) > 1) return false; //되돌려 놓는다
	}
	return true;
}
int set() { //놓는다
	int x = -1, y = -1; //빈 칸 중에 가장 왼쪽 위의 것을 찾는다
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == '.') {
				y = i; x = j;
				break;
			}
		}
		if (y != -1) break; //y가 움직였다는건 더 볼 필요 없이 여기부터 탐색(?)
		//그런 뜻인거 같긴 한데 종만북에 이 부분 이해가 잘 안 됨
	}
	if (y == -1) return 1; //모든 칸을 채웠으면 리턴
	int cnt = 0;
	for (int type = 0; type < 4; type++) {
		if (possible(y, x, type, 1)) cnt += set();
		possible(y, x, type, -1);
	}
	return cnt;
}

int main() {
	scanf("%d", &c); 
	while (c--) {
		scanf("%d %d ", &h, &w);
		for (int i = 0; i < h; i++) {
			scanf("%s", map[i]);
		}
		/*for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == '.') white++;
			}
		}*/
		//if (white % 3 == 1) { //3의 배수가 아니라면 꽉 채울 수 있는 방법이 읍다
		//	printf(">0");
		//}
		//else if (white == 0) {
		//	printf(">1"); //전부 검정일 때 아무 것도 놓지 않는다도 하나의 답이다
		//}
		//else {
		//	printf("%d\n", set());
		//}
		printf("%d\n", set());
	}
}
//https://algospot.com/judge/problem/read/BOARDCOVER
