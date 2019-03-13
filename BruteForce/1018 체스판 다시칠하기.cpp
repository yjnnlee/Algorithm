#include <stdio.h>
#include <algorithm>
using namespace std;

//int n, m, x[] = { -1,-1,0,0 }, y[] = { 0,0,-1,1 };
//char map[55][55];
//
//int find(int i, int j) {
//	if (map[i][j] == 'W') {
//		for (int ii = 0; ii < 4; ii++) {
//			int xx = x[ii] + i;
//			int yy = y[ii] + j;
//			if (xx<0 || xx>m || yy<0 || yy>n) continue;
//			if(map[yy][xx] == 'B')
//		}
//	}
//}

int n, m, minres = 1e9;
char map[55][55];
char mapW[55][55]{ //W로 시작하는 맵
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" }
};

char mapB[55][55]{ //B로 시작하는 맵
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" }
};

int find(int y, int x, int what) {
	int cunt = 0;
	for (int i = y; i < y + 8; i++) {
		for (int j = x; j < x + 8; j++) {
			if (what) {
				if (mapW[i - y][j - x] != map[i][j]) cunt++;
//				printf("1%c 2%c %d %d\n", map[i][j], mapW[i-y][j-x], i, j);
			} //다르면 바꿔야함
			else {
				if (mapB[i - y][j - x] != map[i][j]) cunt++; //B로 시작하는 맵
			}
		}
	}
	//printf(">%d %d %d\n", y, x, cunt);
	return cunt;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", map[i]);
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", map[i][j]);
		}
	}
	왠지 모르겠는데 이렇게 받으면 개행문자까지 들어가서 배열이 이상해진다
	이중for문으로 출력해보면 바깥 for문에 \n를 출력하지 않아도 똑바로 출력되는 것을 볼 수 있다
	왜??? 어쨌든 %s로 받으면 문제 없어짐
	*/

	for (int i = 0; i + 7 < n; i++) {
		for (int j = 0; j + 7 < m; j++) {
			minres = min(minres, min(find(i, j, 1), find(i, j, 0)));			
			//	if (map[i][j] == 'W') {
			//		int cnt = find(i, j, 1);
			//		printf("W %d\n", cnt);
			//		if (minres > cnt) minres = cnt;
			//	}
			//	else if (map[i][j] == 'B'){
			//		int cnt = find(i, j, 0);
			//		printf("B %d\n", cnt);
			//		if (minres > cnt) minres = cnt;
			//	}
			//}
		}
	}
	printf("%d", minres);
}
